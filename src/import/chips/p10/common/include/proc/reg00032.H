/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00032.H $         */
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

#ifndef __PROC_REG00032_H_
#define __PROC_REG00032_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_NVC_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201080d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_NVC_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201080d;
#endif
    return fapi2::getScom(i_target, INT_CQ_NVC_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_NVC_BAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return fapi2::putScom(i_target, INT_CQ_NVC_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return o_data.setBit<INT_CQ_NVC_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_NVC_BAR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return o_data.clearBit<INT_CQ_NVC_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_NVC_BAR_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return i_data.extractToRight<INT_CQ_NVC_BAR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_NVC_BAR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return i_data.getBit<INT_CQ_NVC_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_PAGE_SIZE_64K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_PAGE_SIZE_64K(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_PAGE_SIZE_64K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return o_data.setBit<INT_CQ_NVC_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_NVC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return o_data.clearBit<INT_CQ_NVC_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_NVC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return i_data.extractToRight<INT_CQ_NVC_BAR_PAGE_SIZE_64K,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_NVC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return i_data.getBit<INT_CQ_NVC_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_ADDR_8_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_ADDR_8_39,
           INT_CQ_NVC_BAR_ADDR_8_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_ADDR_8_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_ADDR_8_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_ADDR_8_39,
           INT_CQ_NVC_BAR_ADDR_8_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_ADDR_8_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_NVC_BAR_ADDR_8_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return i_data.extractToRight<INT_CQ_NVC_BAR_ADDR_8_39,
           INT_CQ_NVC_BAR_ADDR_8_39_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_ADDR_8_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_SET_DIV_SEL_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_SET_DIV_SEL_0_2,
           INT_CQ_NVC_BAR_SET_DIV_SEL_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_SET_DIV_SEL_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_SET_DIV_SEL_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_SET_DIV_SEL_0_2,
           INT_CQ_NVC_BAR_SET_DIV_SEL_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_SET_DIV_SEL_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_NVC_BAR_SET_DIV_SEL_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return i_data.extractToRight<INT_CQ_NVC_BAR_SET_DIV_SEL_0_2,
           INT_CQ_NVC_BAR_SET_DIV_SEL_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_SET_DIV_SEL_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_RANGE_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_RANGE_0_4,
           INT_CQ_NVC_BAR_RANGE_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_RANGE_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_NVC_BAR_RANGE_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return o_data.insertFromRight<INT_CQ_NVC_BAR_RANGE_0_4,
           INT_CQ_NVC_BAR_RANGE_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_RANGE_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_NVC_BAR_RANGE_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201080d));
#endif
    return i_data.extractToRight<INT_CQ_NVC_BAR_RANGE_0_4,
           INT_CQ_NVC_BAR_RANGE_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_NVC_BAR_RANGE_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_PMC_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201082b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_PMC_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201082b;
#endif
    return fapi2::getScom(i_target, INT_CQ_PMC_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_PMC_3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201082b));
#endif
    return fapi2::putScom(i_target, INT_CQ_PMC_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PMC_3_INT_CQ_PMC_3_COUNT_0_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201082b));
#endif
    return o_data.insertFromRight<INT_CQ_PMC_3_INT_CQ_PMC_3_COUNT_0_47,
           INT_CQ_PMC_3_INT_CQ_PMC_3_COUNT_0_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PMC_3_INT_CQ_PMC_3_COUNT_0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PMC_3_INT_CQ_PMC_3_COUNT_0_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201082b));
#endif
    return o_data.insertFromRight<INT_CQ_PMC_3_INT_CQ_PMC_3_COUNT_0_47,
           INT_CQ_PMC_3_INT_CQ_PMC_3_COUNT_0_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PMC_3_INT_CQ_PMC_3_COUNT_0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_PMC_3_INT_CQ_PMC_3_COUNT_0_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201082b));
#endif
    return i_data.extractToRight<INT_CQ_PMC_3_INT_CQ_PMC_3_COUNT_0_47,
           INT_CQ_PMC_3_INT_CQ_PMC_3_COUNT_0_47_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PMC_3_INT_CQ_PMC_3_COUNT_0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_TTT_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010807;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_TTT_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010807;
#endif
    return fapi2::getScom(i_target, INT_CQ_TTT_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_TTT_3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return fapi2::putScom(i_target, INT_CQ_TTT_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_VALID_0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_VALID_0_7,
           INT_CQ_TTT_3_VALID_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_VALID_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_VALID_0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_VALID_0_7,
           INT_CQ_TTT_3_VALID_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_VALID_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_3_VALID_0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return i_data.extractToRight<INT_CQ_TTT_3_VALID_0_7,
           INT_CQ_TTT_3_VALID_0_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_VALID_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_ENTRY_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_ENTRY_0_3,
           INT_CQ_TTT_3_ENTRY_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_ENTRY_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_ENTRY_0_3,
           INT_CQ_TTT_3_ENTRY_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_3_ENTRY_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return i_data.extractToRight<INT_CQ_TTT_3_ENTRY_0_3,
           INT_CQ_TTT_3_ENTRY_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_ENTRY_1_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_ENTRY_1_0_3,
           INT_CQ_TTT_3_ENTRY_1_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_1_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_ENTRY_1_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_ENTRY_1_0_3,
           INT_CQ_TTT_3_ENTRY_1_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_1_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_3_ENTRY_1_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return i_data.extractToRight<INT_CQ_TTT_3_ENTRY_1_0_3,
           INT_CQ_TTT_3_ENTRY_1_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_1_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_ENTRY_2_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_ENTRY_2_0_3,
           INT_CQ_TTT_3_ENTRY_2_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_2_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_ENTRY_2_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_ENTRY_2_0_3,
           INT_CQ_TTT_3_ENTRY_2_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_2_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_3_ENTRY_2_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return i_data.extractToRight<INT_CQ_TTT_3_ENTRY_2_0_3,
           INT_CQ_TTT_3_ENTRY_2_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_2_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_ENTRY_3_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_ENTRY_3_0,
           INT_CQ_TTT_3_ENTRY_3_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_ENTRY_3_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_ENTRY_3_0,
           INT_CQ_TTT_3_ENTRY_3_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_3_ENTRY_3_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return i_data.extractToRight<INT_CQ_TTT_3_ENTRY_3_0,
           INT_CQ_TTT_3_ENTRY_3_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_ENTRY_4_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_ENTRY_4_0_3,
           INT_CQ_TTT_3_ENTRY_4_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_4_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_ENTRY_4_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_ENTRY_4_0_3,
           INT_CQ_TTT_3_ENTRY_4_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_4_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_3_ENTRY_4_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return i_data.extractToRight<INT_CQ_TTT_3_ENTRY_4_0_3,
           INT_CQ_TTT_3_ENTRY_4_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_4_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_ENTRY_5_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_ENTRY_5_0_3,
           INT_CQ_TTT_3_ENTRY_5_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_5_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_ENTRY_5_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_ENTRY_5_0_3,
           INT_CQ_TTT_3_ENTRY_5_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_5_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_3_ENTRY_5_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return i_data.extractToRight<INT_CQ_TTT_3_ENTRY_5_0_3,
           INT_CQ_TTT_3_ENTRY_5_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_5_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_ENTRY_6_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_ENTRY_6_0_3,
           INT_CQ_TTT_3_ENTRY_6_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_6_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_ENTRY_6_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_ENTRY_6_0_3,
           INT_CQ_TTT_3_ENTRY_6_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_6_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_3_ENTRY_6_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return i_data.extractToRight<INT_CQ_TTT_3_ENTRY_6_0_3,
           INT_CQ_TTT_3_ENTRY_6_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_6_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_ENTRY_7_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_ENTRY_7_0_3,
           INT_CQ_TTT_3_ENTRY_7_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_7_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_3_ENTRY_7_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_3_ENTRY_7_0_3,
           INT_CQ_TTT_3_ENTRY_7_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_7_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_3_ENTRY_7_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010807));
#endif
    return i_data.extractToRight<INT_CQ_TTT_3_ENTRY_7_0_3,
           INT_CQ_TTT_3_ENTRY_7_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_3_ENTRY_7_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_INFO_ERR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010ad6;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_INFO_ERR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010ad6;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_INFO_ERR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_INFO_ERR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010ad6));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_INFO_ERR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_INFO_ERR_INT_PC_NXC_INFO_ERR_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010ad6));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_INFO_ERR_INT_PC_NXC_INFO_ERR_ERROR,
           INT_PC_NXC_REGS_INFO_ERR_INT_PC_NXC_INFO_ERR_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_INFO_ERR_INT_PC_NXC_INFO_ERR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_INFO_ERR_INT_PC_NXC_INFO_ERR_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010ad6));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_INFO_ERR_INT_PC_NXC_INFO_ERR_ERROR,
           INT_PC_NXC_REGS_INFO_ERR_INT_PC_NXC_INFO_ERR_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_INFO_ERR_INT_PC_NXC_INFO_ERR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_INFO_ERR_INT_PC_NXC_INFO_ERR_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010ad6));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_INFO_ERR_INT_PC_NXC_INFO_ERR_ERROR,
           INT_PC_NXC_REGS_INFO_ERR_INT_PC_NXC_INFO_ERR_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_INFO_ERR_INT_PC_NXC_INFO_ERR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_WATCH0_DATA3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010aa7;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_WATCH0_DATA3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010aa7;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_WATCH0_DATA3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_WATCH0_DATA3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010aa7));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_WATCH0_DATA3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_WATCH1_SPEC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010aa8;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_WATCH1_SPEC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010aa8;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_WATCH1_SPEC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_WATCH1_SPEC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010aa8));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_WATCH1_SPEC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_AIB_RX_CRD_DAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a12;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_AIB_RX_CRD_DAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a12;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_AIB_RX_CRD_DAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_AIB_RX_CRD_DAT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_AIB_RX_CRD_DAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_0_1,
           INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_0_1,
           INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_0_1,
           INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH0_MAX_DAT_CRD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH0_MAX_DAT_CRD,
           INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH0_MAX_DAT_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH0_MAX_DAT_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH0_MAX_DAT_CRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH0_MAX_DAT_CRD,
           INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH0_MAX_DAT_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH0_MAX_DAT_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH0_MAX_DAT_CRD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH0_MAX_DAT_CRD,
           INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH0_MAX_DAT_CRD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH0_MAX_DAT_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_8_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_8_9,
           INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_8_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_8_9,
           INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_8_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_8_9,
           INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_8_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH2_MAX_DAT_CRD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH2_MAX_DAT_CRD,
           INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH2_MAX_DAT_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH2_MAX_DAT_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH2_MAX_DAT_CRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH2_MAX_DAT_CRD,
           INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH2_MAX_DAT_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH2_MAX_DAT_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH2_MAX_DAT_CRD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH2_MAX_DAT_CRD,
           INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH2_MAX_DAT_CRD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH2_MAX_DAT_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_16_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_16_17,
           INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_16_17_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_16_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_16_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_16_17,
           INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_16_17_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_16_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_16_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_16_17,
           INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_16_17_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_16_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH3_MAX_DAT_CRD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH3_MAX_DAT_CRD,
           INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH3_MAX_DAT_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH3_MAX_DAT_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH3_MAX_DAT_CRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH3_MAX_DAT_CRD,
           INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH3_MAX_DAT_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH3_MAX_DAT_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH3_MAX_DAT_CRD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH3_MAX_DAT_CRD,
           INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH3_MAX_DAT_CRD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH3_MAX_DAT_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_24_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_24_25,
           INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_24_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_24_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_24_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_24_25,
           INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_24_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_24_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_24_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_24_25,
           INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_24_25_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_24_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH6_MAX_DAT_CRD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH6_MAX_DAT_CRD,
           INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH6_MAX_DAT_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH6_MAX_DAT_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH6_MAX_DAT_CRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH6_MAX_DAT_CRD,
           INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH6_MAX_DAT_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH6_MAX_DAT_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH6_MAX_DAT_CRD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH6_MAX_DAT_CRD,
           INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH6_MAX_DAT_CRD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_CQ_CH6_MAX_DAT_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_32_33,
           INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_32_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_32_33,
           INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_32_33,
           INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_32_33_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_VC_CH6_MAX_DAT_CRD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_VC_CH6_MAX_DAT_CRD,
           INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_VC_CH6_MAX_DAT_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_VC_CH6_MAX_DAT_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_VC_CH6_MAX_DAT_CRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_VC_CH6_MAX_DAT_CRD,
           INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_VC_CH6_MAX_DAT_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_VC_CH6_MAX_DAT_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_VC_CH6_MAX_DAT_CRD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a12));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_VC_CH6_MAX_DAT_CRD,
           INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_VC_CH6_MAX_DAT_CRD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_RX_CRD_DAT_PC_AIB_VC_CH6_MAX_DAT_CRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_ERR0_WOF_DETAIL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010ac3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_ERR0_WOF_DETAIL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010ac3;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_ERR0_WOF_DETAIL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_ERR0_WOF_DETAIL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010ac3));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_ERR0_WOF_DETAIL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_ERR0_WOF_DETAIL_INT_PC_ERR0_WOF_DETAIL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010ac3));
#endif
    return o_data.insertFromRight<INT_PC_REGS_ERR0_WOF_DETAIL_INT_PC_ERR0_WOF_DETAIL,
           INT_PC_REGS_ERR0_WOF_DETAIL_INT_PC_ERR0_WOF_DETAIL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR0_WOF_DETAIL_INT_PC_ERR0_WOF_DETAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_ERR0_WOF_DETAIL_INT_PC_ERR0_WOF_DETAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010ac3));
#endif
    return o_data.insertFromRight<INT_PC_REGS_ERR0_WOF_DETAIL_INT_PC_ERR0_WOF_DETAIL,
           INT_PC_REGS_ERR0_WOF_DETAIL_INT_PC_ERR0_WOF_DETAIL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR0_WOF_DETAIL_INT_PC_ERR0_WOF_DETAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_ERR0_WOF_DETAIL_INT_PC_ERR0_WOF_DETAIL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010ac3));
#endif
    return i_data.extractToRight<INT_PC_REGS_ERR0_WOF_DETAIL_INT_PC_ERR0_WOF_DETAIL,
           INT_PC_REGS_ERR0_WOF_DETAIL_INT_PC_ERR0_WOF_DETAIL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_ERR0_WOF_DETAIL_INT_PC_ERR0_WOF_DETAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_TCTXT_DEBUG_ADDR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010b2c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_TCTXT_DEBUG_ADDR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010b2c;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_TCTXT_DEBUG_ADDR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_TCTXT_DEBUG_ADDR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010b2c));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_TCTXT_DEBUG_ADDR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010b2c));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010b2c));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010b2c));
#endif
    return o_data.setBit<INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010b2c));
#endif
    return o_data.clearBit<INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010b2c));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010b2c));
#endif
    return i_data.getBit<INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_DEBUG_ADDR_RESERVED_1_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010b2c));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_DEBUG_ADDR_RESERVED_1_4,
           INT_PC_REGS_TCTXT_DEBUG_ADDR_RESERVED_1_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_TCTXT_DEBUG_ADDR_RESERVED_1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_DEBUG_ADDR_RESERVED_1_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010b2c));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_DEBUG_ADDR_RESERVED_1_4,
           INT_PC_REGS_TCTXT_DEBUG_ADDR_RESERVED_1_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_TCTXT_DEBUG_ADDR_RESERVED_1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_DEBUG_ADDR_RESERVED_1_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010b2c));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_DEBUG_ADDR_RESERVED_1_4,
           INT_PC_REGS_TCTXT_DEBUG_ADDR_RESERVED_1_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_TCTXT_DEBUG_ADDR_RESERVED_1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_DW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010b2c));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_DW,
           INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_DW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_DW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_DW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010b2c));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_DW,
           INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_DW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_DW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_DW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010b2c));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_DW,
           INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_DW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_DW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_THRDID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010b2c));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_THRDID,
           INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_THRDID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_THRDID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_THRDID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010b2c));
#endif
    return o_data.insertFromRight<INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_THRDID,
           INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_THRDID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_THRDID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_THRDID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010b2c));
#endif
    return i_data.extractToRight<INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_THRDID,
           INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_THRDID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_TCTXT_DEBUG_ADDR_DBG_THRDID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_EASC_DBG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010974;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_EASC_DBG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010974;
#endif
    return fapi2::getScom(i_target, INT_VC_EASC_DBG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_EASC_DBG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return fapi2::putScom(i_target, INT_VC_EASC_DBG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_RESERVED_24_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_RESERVED_24_31,
           INT_VC_EASC_DBG_RESERVED_24_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_RESERVED_24_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_RESERVED_24_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_RESERVED_24_31,
           INT_VC_EASC_DBG_RESERVED_24_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_RESERVED_24_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_DBG_RESERVED_24_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return i_data.extractToRight<INT_VC_EASC_DBG_RESERVED_24_31,
           INT_VC_EASC_DBG_RESERVED_24_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_RESERVED_24_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_WAY_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_WAY_DISABLE,
           INT_VC_EASC_DBG_WAY_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_WAY_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_WAY_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_WAY_DISABLE,
           INT_VC_EASC_DBG_WAY_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_WAY_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_DBG_WAY_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return i_data.extractToRight<INT_VC_EASC_DBG_WAY_DISABLE,
           INT_VC_EASC_DBG_WAY_DISABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_WAY_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_DIS_TAG_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_DIS_TAG_ECC_CORRECTION,
           INT_VC_EASC_DBG_DIS_TAG_ECC_CORRECTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_TAG_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_DIS_TAG_ECC_CORRECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_DIS_TAG_ECC_CORRECTION,
           INT_VC_EASC_DBG_DIS_TAG_ECC_CORRECTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_TAG_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_DBG_DIS_TAG_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return i_data.extractToRight<INT_VC_EASC_DBG_DIS_TAG_ECC_CORRECTION,
           INT_VC_EASC_DBG_DIS_TAG_ECC_CORRECTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_TAG_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.setBit<INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.clearBit<INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return i_data.extractToRight<INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return i_data.getBit<INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_STATE_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_DIS_DATA_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_DIS_DATA_ECC_CORRECTION,
           INT_VC_EASC_DBG_DIS_DATA_ECC_CORRECTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_DATA_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_DIS_DATA_ECC_CORRECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_DIS_DATA_ECC_CORRECTION,
           INT_VC_EASC_DBG_DIS_DATA_ECC_CORRECTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_DATA_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_DBG_DIS_DATA_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return i_data.extractToRight<INT_VC_EASC_DBG_DIS_DATA_ECC_CORRECTION,
           INT_VC_EASC_DBG_DIS_DATA_ECC_CORRECTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_DATA_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.setBit<INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.clearBit<INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return i_data.extractToRight<INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return i_data.getBit<INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_DIS_CTRL_ECC_CORRECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.setBit<INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.clearBit<INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return i_data.extractToRight<INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return i_data.getBit<INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.setBit<INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.clearBit<INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return i_data.extractToRight<INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return i_data.getBit<INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_ECC_ERR_INJ_ARRAY_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_ECC_ERR_INJ_ARRAY_SEL,
           INT_VC_EASC_DBG_ECC_ERR_INJ_ARRAY_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_ECC_ERR_INJ_ARRAY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_ECC_ERR_INJ_ARRAY_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_ECC_ERR_INJ_ARRAY_SEL,
           INT_VC_EASC_DBG_ECC_ERR_INJ_ARRAY_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_ECC_ERR_INJ_ARRAY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_DBG_ECC_ERR_INJ_ARRAY_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return i_data.extractToRight<INT_VC_EASC_DBG_ECC_ERR_INJ_ARRAY_SEL,
           INT_VC_EASC_DBG_ECC_ERR_INJ_ARRAY_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_ECC_ERR_INJ_ARRAY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_TRACE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_TRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.setBit<INT_VC_EASC_DBG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EASC_DBG_TRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.clearBit<INT_VC_EASC_DBG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_DBG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return i_data.extractToRight<INT_VC_EASC_DBG_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_EASC_DBG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return i_data.getBit<INT_VC_EASC_DBG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_MAX_DMA_READ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_MAX_DMA_READ,
           INT_VC_EASC_DBG_MAX_DMA_READ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_MAX_DMA_READ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_MAX_DMA_READ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_MAX_DMA_READ,
           INT_VC_EASC_DBG_MAX_DMA_READ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_MAX_DMA_READ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_DBG_MAX_DMA_READ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010974));
#endif
    return i_data.extractToRight<INT_VC_EASC_DBG_MAX_DMA_READ,
           INT_VC_EASC_DBG_MAX_DMA_READ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_MAX_DMA_READ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_EASC_HASH_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201096a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_EASC_HASH_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201096a;
#endif
    return fapi2::getScom(i_target, INT_VC_EASC_HASH_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_EASC_HASH_2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return fapi2::putScom(i_target, INT_VC_EASC_HASH_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_2_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_2_8,
           INT_VC_EASC_HASH_2_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_2_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_2_8,
           INT_VC_EASC_HASH_2_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_HASH_2_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return i_data.extractToRight<INT_VC_EASC_HASH_2_8,
           INT_VC_EASC_HASH_2_8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_2_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_2_9,
           INT_VC_EASC_HASH_2_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_2_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_2_9,
           INT_VC_EASC_HASH_2_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_HASH_2_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return i_data.extractToRight<INT_VC_EASC_HASH_2_9,
           INT_VC_EASC_HASH_2_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_2_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_2_10,
           INT_VC_EASC_HASH_2_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_2_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_2_10,
           INT_VC_EASC_HASH_2_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_HASH_2_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return i_data.extractToRight<INT_VC_EASC_HASH_2_10,
           INT_VC_EASC_HASH_2_10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_2_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_2_11,
           INT_VC_EASC_HASH_2_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_2_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_2_11,
           INT_VC_EASC_HASH_2_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_HASH_2_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return i_data.extractToRight<INT_VC_EASC_HASH_2_11,
           INT_VC_EASC_HASH_2_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_2_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_2_12,
           INT_VC_EASC_HASH_2_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_2_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_2_12,
           INT_VC_EASC_HASH_2_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_HASH_2_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return i_data.extractToRight<INT_VC_EASC_HASH_2_12,
           INT_VC_EASC_HASH_2_12_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_2_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_2_13,
           INT_VC_EASC_HASH_2_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_2_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_2_13,
           INT_VC_EASC_HASH_2_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_HASH_2_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return i_data.extractToRight<INT_VC_EASC_HASH_2_13,
           INT_VC_EASC_HASH_2_13_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_2_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_2_14,
           INT_VC_EASC_HASH_2_14_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_2_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_2_14,
           INT_VC_EASC_HASH_2_14_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_HASH_2_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return i_data.extractToRight<INT_VC_EASC_HASH_2_14,
           INT_VC_EASC_HASH_2_14_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_2_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_2_15,
           INT_VC_EASC_HASH_2_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_2_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_2_15,
           INT_VC_EASC_HASH_2_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_HASH_2_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096a));
#endif
    return i_data.extractToRight<INT_VC_EASC_HASH_2_15,
           INT_VC_EASC_HASH_2_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_2_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_EASC_PERF_EVENT_SEL_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201097a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_EASC_PERF_EVENT_SEL_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201097a;
#endif
    return fapi2::getScom(i_target, INT_VC_EASC_PERF_EVENT_SEL_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_EASC_PERF_EVENT_SEL_3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201097a));
#endif
    return fapi2::putScom(i_target, INT_VC_EASC_PERF_EVENT_SEL_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_3_PROC_UPDATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201097a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_3_PROC_UPDATE,
           INT_VC_EASC_PERF_EVENT_SEL_3_PROC_UPDATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_3_PROC_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_3_PROC_UPDATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201097a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_3_PROC_UPDATE,
           INT_VC_EASC_PERF_EVENT_SEL_3_PROC_UPDATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_3_PROC_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_PERF_EVENT_SEL_3_PROC_UPDATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201097a));
#endif
    return i_data.extractToRight<INT_VC_EASC_PERF_EVENT_SEL_3_PROC_UPDATE,
           INT_VC_EASC_PERF_EVENT_SEL_3_PROC_UPDATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_3_PROC_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201097a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH,
           INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201097a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH,
           INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201097a));
#endif
    return i_data.extractToRight<INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH,
           INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201097a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH_REPLAY,
           INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201097a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH_REPLAY,
           INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201097a));
#endif
    return i_data.extractToRight<INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH_REPLAY,
           INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_3_CNT_EAS_FETCH_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_3_CNT_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201097a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_3_CNT_MASK,
           INT_VC_EASC_PERF_EVENT_SEL_3_CNT_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_3_CNT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_3_CNT_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201097a));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_3_CNT_MASK,
           INT_VC_EASC_PERF_EVENT_SEL_3_CNT_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_3_CNT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_PERF_EVENT_SEL_3_CNT_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201097a));
#endif
    return i_data.extractToRight<INT_VC_EASC_PERF_EVENT_SEL_3_CNT_MASK,
           INT_VC_EASC_PERF_EVENT_SEL_3_CNT_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_3_CNT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_PERF_EVENT_SEL_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201099a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_PERF_EVENT_SEL_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201099a;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_PERF_EVENT_SEL_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_PERF_EVENT_SEL_3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_PERF_EVENT_SEL_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_END_FETCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_END_FETCH,
           INT_VC_ENDC_PERF_EVENT_SEL_3_END_FETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_END_FETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_END_FETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_END_FETCH,
           INT_VC_ENDC_PERF_EVENT_SEL_3_END_FETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_END_FETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_3_END_FETCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_3_END_FETCH,
           INT_VC_ENDC_PERF_EVENT_SEL_3_END_FETCH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_END_FETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_EQPOST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_EQPOST,
           INT_VC_ENDC_PERF_EVENT_SEL_3_EQPOST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_EQPOST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_EQPOST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_EQPOST,
           INT_VC_ENDC_PERF_EVENT_SEL_3_EQPOST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_EQPOST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_3_EQPOST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_3_EQPOST,
           INT_VC_ENDC_PERF_EVENT_SEL_3_EQPOST_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_EQPOST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_RESUME_INT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_RESUME_INT,
           INT_VC_ENDC_PERF_EVENT_SEL_3_RESUME_INT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_RESUME_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_RESUME_INT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_RESUME_INT,
           INT_VC_ENDC_PERF_EVENT_SEL_3_RESUME_INT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_RESUME_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_3_RESUME_INT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_3_RESUME_INT,
           INT_VC_ENDC_PERF_EVENT_SEL_3_RESUME_INT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_RESUME_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_EBB_INT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_EBB_INT,
           INT_VC_ENDC_PERF_EVENT_SEL_3_EBB_INT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_EBB_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_EBB_INT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_EBB_INT,
           INT_VC_ENDC_PERF_EVENT_SEL_3_EBB_INT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_EBB_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_3_EBB_INT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_3_EBB_INT,
           INT_VC_ENDC_PERF_EVENT_SEL_3_EBB_INT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_EBB_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_VP_INT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_VP_INT,
           INT_VC_ENDC_PERF_EVENT_SEL_3_VP_INT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_VP_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_VP_INT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_VP_INT,
           INT_VC_ENDC_PERF_EVENT_SEL_3_VP_INT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_VP_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_3_VP_INT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_3_VP_INT,
           INT_VC_ENDC_PERF_EVENT_SEL_3_VP_INT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_VP_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_LS_INT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_LS_INT,
           INT_VC_ENDC_PERF_EVENT_SEL_3_LS_INT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_LS_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_LS_INT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_LS_INT,
           INT_VC_ENDC_PERF_EVENT_SEL_3_LS_INT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_LS_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_3_LS_INT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_3_LS_INT,
           INT_VC_ENDC_PERF_EVENT_SEL_3_LS_INT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_LS_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_BROADCAST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_BROADCAST,
           INT_VC_ENDC_PERF_EVENT_SEL_3_BROADCAST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_BROADCAST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_BROADCAST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_BROADCAST,
           INT_VC_ENDC_PERF_EVENT_SEL_3_BROADCAST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_BROADCAST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_3_BROADCAST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_3_BROADCAST,
           INT_VC_ENDC_PERF_EVENT_SEL_3_BROADCAST_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_BROADCAST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_INT_ESB_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_INT_ESB_RESET,
           INT_VC_ENDC_PERF_EVENT_SEL_3_INT_ESB_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_INT_ESB_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_INT_ESB_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_INT_ESB_RESET,
           INT_VC_ENDC_PERF_EVENT_SEL_3_INT_ESB_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_INT_ESB_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_3_INT_ESB_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_3_INT_ESB_RESET,
           INT_VC_ENDC_PERF_EVENT_SEL_3_INT_ESB_RESET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_INT_ESB_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_EQ_FORWARDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_EQ_FORWARDING,
           INT_VC_ENDC_PERF_EVENT_SEL_3_EQ_FORWARDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_EQ_FORWARDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_EQ_FORWARDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_EQ_FORWARDING,
           INT_VC_ENDC_PERF_EVENT_SEL_3_EQ_FORWARDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_EQ_FORWARDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_3_EQ_FORWARDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_3_EQ_FORWARDING,
           INT_VC_ENDC_PERF_EVENT_SEL_3_EQ_FORWARDING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_EQ_FORWARDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_ESCALATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_ESCALATE,
           INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_ESCALATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_ESCALATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_ESCALATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_ESCALATE,
           INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_ESCALATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_ESCALATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_ESCALATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_ESCALATE,
           INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_ESCALATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_ESCALATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_FW_FORWARD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_FW_FORWARD,
           INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_FW_FORWARD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_FW_FORWARD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_FW_FORWARD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_FW_FORWARD,
           INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_FW_FORWARD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_FW_FORWARD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_FW_FORWARD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_FW_FORWARD,
           INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_FW_FORWARD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_FW_FORWARD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_ESCALATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_ESCALATE,
           INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_ESCALATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_ESCALATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_ESCALATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_ESCALATE,
           INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_ESCALATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_ESCALATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_ESCALATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_ESCALATE,
           INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_ESCALATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_ESCALATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_FW_FORWARD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_FW_FORWARD,
           INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_FW_FORWARD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_FW_FORWARD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_FW_FORWARD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_FW_FORWARD,
           INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_FW_FORWARD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_FW_FORWARD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_FW_FORWARD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_FW_FORWARD,
           INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_FW_FORWARD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_FW_FORWARD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_LD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_LD,
           INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_LD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_LD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_LD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_LD,
           INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_LD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_LD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_LD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_LD,
           INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_LD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_LD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_NXC_LD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_NXC_LD,
           INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_NXC_LD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_NXC_LD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_NXC_LD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_NXC_LD,
           INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_NXC_LD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_NXC_LD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_NXC_LD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_NXC_LD,
           INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_NXC_LD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_REMOTE_NXC_LD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_TEND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_TEND,
           INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_TEND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_TEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_TEND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_TEND,
           INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_TEND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_TEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_TEND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201099a));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_TEND,
           INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_TEND_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_3_LOCAL_NXC_TEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_WATCH3_DATA1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20109bd;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_WATCH3_DATA1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20109bd;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_WATCH3_DATA1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_WATCH3_DATA1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20109bd));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_WATCH3_DATA1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_QUEUES_CFG_REM_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201091b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_QUEUES_CFG_REM_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201091b;
#endif
    return fapi2::getScom(i_target, INT_VC_QUEUES_CFG_REM_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_QUEUES_CFG_REM_4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return fapi2::putScom(i_target, INT_VC_QUEUES_CFG_REM_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_PREFETCH_DISTANCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_PREFETCH_DISTANCE,
           INT_VC_QUEUES_CFG_REM_4_IRQ_PREFETCH_DISTANCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_PREFETCH_DISTANCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_PREFETCH_DISTANCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_PREFETCH_DISTANCE,
           INT_VC_QUEUES_CFG_REM_4_IRQ_PREFETCH_DISTANCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_PREFETCH_DISTANCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_IRQ_PREFETCH_DISTANCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_IRQ_PREFETCH_DISTANCE,
           INT_VC_QUEUES_CFG_REM_4_IRQ_PREFETCH_DISTANCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_PREFETCH_DISTANCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_RESERVED_8_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_8_10,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_8_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_8_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_RESERVED_8_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_8_10,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_8_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_8_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_RESERVED_8_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_8_10,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_8_10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_8_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_CQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_CQ,
           INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_CQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_CQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_CQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_CQ,
           INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_CQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_CQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_CQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_CQ,
           INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_CQ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_CQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_RESERVED_16_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_16_18,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_16_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_16_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_RESERVED_16_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_16_18,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_16_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_16_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_RESERVED_16_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_16_18,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_16_18_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_16_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_PC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_PC,
           INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_PC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_PC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_PC,
           INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_PC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_PC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_PC,
           INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_PC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_CRD_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_NB_OUTSTANDING_DEM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_NB_OUTSTANDING_DEM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_MAX_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_MIN_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_MIN_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_4_IRQ_MIN_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_MIN_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_MIN_NB_OUTSTANDING_DEM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_MIN_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_4_IRQ_MIN_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_MIN_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_IRQ_MIN_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_IRQ_MIN_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_4_IRQ_MIN_NB_OUTSTANDING_DEM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_MIN_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_32_33,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_RESERVED_32_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_32_33,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_32_33,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_32_33_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_4_IRQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_4_IRQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_4_IRQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_IRQ_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_IRQ_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_4_IRQ_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_4_IRQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_RESERVED_36_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_36_37,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_36_37_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_36_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_RESERVED_36_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_36_37,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_36_37_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_36_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_RESERVED_36_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_36_37,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_36_37_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_36_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_RESERVED_40_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_40_41,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_40_41_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_RESERVED_40_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_40_41,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_40_41_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_RESERVED_40_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_40_41,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_40_41_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_MEM_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_ERQ_MEM_SIZE,
           INT_VC_QUEUES_CFG_REM_4_ERQ_MEM_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_MEM_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_ERQ_MEM_SIZE,
           INT_VC_QUEUES_CFG_REM_4_ERQ_MEM_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_ERQ_MEM_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_ERQ_MEM_SIZE,
           INT_VC_QUEUES_CFG_REM_4_ERQ_MEM_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_RESERVED_48_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_48_49,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_48_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_RESERVED_48_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_48_49,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_48_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_RESERVED_48_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_RESERVED_48_49,
           INT_VC_QUEUES_CFG_REM_4_RESERVED_48_49_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_ERQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_ERQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_4_ERQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_4_ERQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_4_ERQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_ERQ_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_ERQ_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_4_ERQ_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_4_ERQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091b));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_4_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_QUEUES_PERF_EVENT_SEL_7(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201092d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_QUEUES_PERF_EVENT_SEL_7(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201092d;
#endif
    return fapi2::getScom(i_target, INT_VC_QUEUES_PERF_EVENT_SEL_7, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_QUEUES_PERF_EVENT_SEL_7(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return fapi2::putScom(i_target, INT_VC_QUEUES_PERF_EVENT_SEL_7, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_7_FROM_AIB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_FROM_AIB,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_FROM_AIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_FROM_AIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_7_FROM_AIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_FROM_AIB,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_FROM_AIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_FROM_AIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_7_FROM_AIB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_FROM_AIB,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_FROM_AIB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_FROM_AIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_7_IRQ_TO_IQA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_IRQ_TO_IQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_IRQ_TO_IQA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_IRQ_TO_IQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_7_IRQ_TO_IQA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_IRQ_TO_IQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_IRQ_TO_IQA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_IRQ_TO_IQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_7_IRQ_TO_IQA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_IRQ_TO_IQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_IRQ_TO_IQA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_IRQ_TO_IQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_DPS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_DPS,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_DPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_DPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_DPS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_DPS,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_DPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_DPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_DPS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_DPS,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_DPS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_DPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_IQS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_IQS,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_IQS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_IQS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_IQS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_IQS,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_IQS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_IQS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_IQS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_IQS,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_IQS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_IQA_TO_IQS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_7_IQS_TO_EQA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_IQS_TO_EQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_IQS_TO_EQA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_IQS_TO_EQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_7_IQS_TO_EQA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_IQS_TO_EQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_IQS_TO_EQA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_IQS_TO_EQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_7_IQS_TO_EQA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_IQS_TO_EQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_IQS_TO_EQA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_IQS_TO_EQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ERQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ERQ,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ERQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ERQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ERQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ERQ,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ERQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ERQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ERQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ERQ,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ERQ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ERQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ATX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ATX,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ATX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ATX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ATX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ATX,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ATX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ATX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ATX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ATX,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ATX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ATX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ENDC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ENDC,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ENDC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ENDC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ENDC,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ENDC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ENDC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092d));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ENDC,
           INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ENDC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_7_EQA_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_BANK0_CHA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x301080d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_BANK0_CHA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x301080d;
#endif
    return fapi2::getScom(i_target, MCD_BANK0_CHA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_BANK0_CHA(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return fapi2::putScom(i_target, MCD_BANK0_CHA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.setBit<MCD_BANK0_CHA_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_CHA_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.clearBit<MCD_BANK0_CHA_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_CHA_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return i_data.extractToRight<MCD_BANK0_CHA_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_CHA_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return i_data.getBit<MCD_BANK0_CHA_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_CPG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_CPG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_CPG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_CPG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_CPG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.setBit<MCD_BANK0_CHA_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_CHA_CPG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.clearBit<MCD_BANK0_CHA_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_CHA_CPG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return i_data.extractToRight<MCD_BANK0_CHA_CPG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_CHA_CPG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return i_data.getBit<MCD_BANK0_CHA_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_GRP_MBR_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_GRP_MBR_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_GRP_MBR_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_GRP_MBR_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.setBit<MCD_BANK0_CHA_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_CHA_GRP_MBR_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.clearBit<MCD_BANK0_CHA_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_CHA_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return i_data.extractToRight<MCD_BANK0_CHA_GRP_MBR_ID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_CHA_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return i_data.getBit<MCD_BANK0_CHA_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_ALWAYS_RTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_ALWAYS_RTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_ALWAYS_RTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_ALWAYS_RTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.setBit<MCD_BANK0_CHA_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_CHA_ALWAYS_RTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.clearBit<MCD_BANK0_CHA_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_CHA_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return i_data.extractToRight<MCD_BANK0_CHA_ALWAYS_RTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_CHA_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return i_data.getBit<MCD_BANK0_CHA_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_SMF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.setBit<MCD_BANK0_CHA_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_CHA_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.clearBit<MCD_BANK0_CHA_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_CHA_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return i_data.extractToRight<MCD_BANK0_CHA_SMF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_CHA_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return i_data.getBit<MCD_BANK0_CHA_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_GRP_SIZE,
           MCD_BANK0_CHA_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_GRP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_GRP_SIZE,
           MCD_BANK0_CHA_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_CHA_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return i_data.extractToRight<MCD_BANK0_CHA_GRP_SIZE,
           MCD_BANK0_CHA_GRP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_GRP_BASE,
           MCD_BANK0_CHA_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_CHA_GRP_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return o_data.insertFromRight<MCD_BANK0_CHA_GRP_BASE,
           MCD_BANK0_CHA_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_CHA_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080d));
#endif
    return i_data.extractToRight<MCD_BANK0_CHA_GRP_BASE,
           MCD_BANK0_CHA_GRP_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_CHA_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_BANK0_TOP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x301080a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_BANK0_TOP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x301080a;
#endif
    return fapi2::getScom(i_target, MCD_BANK0_TOP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_BANK0_TOP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return fapi2::putScom(i_target, MCD_BANK0_TOP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.setBit<MCD_BANK0_TOP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_TOP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.clearBit<MCD_BANK0_TOP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TOP_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return i_data.extractToRight<MCD_BANK0_TOP_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_TOP_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return i_data.getBit<MCD_BANK0_TOP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_CPG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_CPG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_CPG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_CPG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_CPG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.setBit<MCD_BANK0_TOP_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_TOP_CPG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.clearBit<MCD_BANK0_TOP_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TOP_CPG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return i_data.extractToRight<MCD_BANK0_TOP_CPG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_TOP_CPG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return i_data.getBit<MCD_BANK0_TOP_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_GRP_MBR_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_GRP_MBR_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_GRP_MBR_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_GRP_MBR_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.setBit<MCD_BANK0_TOP_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_TOP_GRP_MBR_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.clearBit<MCD_BANK0_TOP_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TOP_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return i_data.extractToRight<MCD_BANK0_TOP_GRP_MBR_ID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_TOP_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return i_data.getBit<MCD_BANK0_TOP_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_ALWAYS_RTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_ALWAYS_RTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_ALWAYS_RTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_ALWAYS_RTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.setBit<MCD_BANK0_TOP_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_TOP_ALWAYS_RTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.clearBit<MCD_BANK0_TOP_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TOP_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return i_data.extractToRight<MCD_BANK0_TOP_ALWAYS_RTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_TOP_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return i_data.getBit<MCD_BANK0_TOP_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_SMF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.setBit<MCD_BANK0_TOP_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_TOP_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.clearBit<MCD_BANK0_TOP_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TOP_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return i_data.extractToRight<MCD_BANK0_TOP_SMF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_TOP_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return i_data.getBit<MCD_BANK0_TOP_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_GRP_SIZE,
           MCD_BANK0_TOP_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_GRP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_GRP_SIZE,
           MCD_BANK0_TOP_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TOP_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return i_data.extractToRight<MCD_BANK0_TOP_GRP_SIZE,
           MCD_BANK0_TOP_GRP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_GRP_BASE,
           MCD_BANK0_TOP_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TOP_GRP_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return o_data.insertFromRight<MCD_BANK0_TOP_GRP_BASE,
           MCD_BANK0_TOP_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TOP_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301080a));
#endif
    return i_data.extractToRight<MCD_BANK0_TOP_GRP_BASE,
           MCD_BANK0_TOP_GRP_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TOP_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_CFG_NMMU_CTL_SLB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c54;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_CFG_NMMU_CTL_SLB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c54;
#endif
    return fapi2::getScom(i_target, MM0_MM_CFG_NMMU_CTL_SLB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_CFG_NMMU_CTL_SLB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return fapi2::putScom(i_target, MM0_MM_CFG_NMMU_CTL_SLB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_MBR_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_MBR_DIS,
           MM0_MM_CFG_NMMU_CTL_SLB_MBR_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_MBR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_MBR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_MBR_DIS,
           MM0_MM_CFG_NMMU_CTL_SLB_MBR_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_MBR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_MBR_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_MBR_DIS,
           MM0_MM_CFG_NMMU_CTL_SLB_MBR_DIS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_MBR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL,
           MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL,
           MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL,
           MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL,
           MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL,
           MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL,
           MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c54));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c15;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c15;
#endif
    return fapi2::getScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return fapi2::putScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.setBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.clearBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.getBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.setBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.clearBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.getBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.setBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.clearBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.getBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.setBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.clearBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.getBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.setBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.clearBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.getBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.setBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.clearBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.getBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.setBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.clearBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.getBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.setBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.clearBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.getBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.setBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.clearBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.getBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.setBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.clearBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.getBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.setBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.clearBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.getBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.setBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.clearBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.getBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.setBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.clearBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.getBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.setBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.clearBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.getBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c15));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_WOF_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c08;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_WOF_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c08;
#endif
    return fapi2::getScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_WOF_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_WOF_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c08));
#endif
    return fapi2::putScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_WOF_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_NMMU_ERR_LOG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c57;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_NMMU_ERR_LOG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c57;
#endif
    return fapi2::getScom(i_target, MM0_MM_NMMU_ERR_LOG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_NMMU_ERR_LOG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return fapi2::putScom(i_target, MM0_MM_NMMU_ERR_LOG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_NMMU_ERR_LOG_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return o_data.insertFromRight<MM0_MM_NMMU_ERR_LOG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_NMMU_ERR_LOG_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return o_data.insertFromRight<MM0_MM_NMMU_ERR_LOG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_NMMU_ERR_LOG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return o_data.setBit<MM0_MM_NMMU_ERR_LOG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_NMMU_ERR_LOG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return o_data.clearBit<MM0_MM_NMMU_ERR_LOG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_NMMU_ERR_LOG_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return i_data.extractToRight<MM0_MM_NMMU_ERR_LOG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_NMMU_ERR_LOG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return i_data.getBit<MM0_MM_NMMU_ERR_LOG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return o_data.insertFromRight<MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return o_data.insertFromRight<MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return o_data.setBit<MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return o_data.clearBit<MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return i_data.extractToRight<MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return i_data.getBit<MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_NMMU_ERR_LOG_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return o_data.insertFromRight<MM0_MM_NMMU_ERR_LOG_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_NMMU_ERR_LOG_OVERLAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return o_data.insertFromRight<MM0_MM_NMMU_ERR_LOG_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_NMMU_ERR_LOG_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return o_data.setBit<MM0_MM_NMMU_ERR_LOG_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_NMMU_ERR_LOG_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return o_data.clearBit<MM0_MM_NMMU_ERR_LOG_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_NMMU_ERR_LOG_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return i_data.extractToRight<MM0_MM_NMMU_ERR_LOG_OVERLAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_NMMU_ERR_LOG_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return i_data.getBit<MM0_MM_NMMU_ERR_LOG_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_NMMU_ERR_LOG_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return o_data.insertFromRight<MM0_MM_NMMU_ERR_LOG_MULT_SEL,
           MM0_MM_NMMU_ERR_LOG_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_NMMU_ERR_LOG_MULT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return o_data.insertFromRight<MM0_MM_NMMU_ERR_LOG_MULT_SEL,
           MM0_MM_NMMU_ERR_LOG_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_NMMU_ERR_LOG_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c57));
#endif
    return i_data.extractToRight<MM0_MM_NMMU_ERR_LOG_MULT_SEL,
           MM0_MM_NMMU_ERR_LOG_MULT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_ERR_LOG_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010c24;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010c24;
#endif
    return fapi2::getScom(i_target, MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3010c24));
#endif
    return fapi2::putScom(i_target, MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c24));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63,
           MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c24));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63,
           MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c24));
#endif
    return i_data.extractToRight<MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63,
           MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_CH4_GZIP_ERRRPT_HOLD_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011152;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_CH4_GZIP_ERRRPT_HOLD_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011152;
#endif
    return fapi2::getScom(i_target, NX_CH4_GZIP_ERRRPT_HOLD_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_CH4_GZIP_ERRRPT_HOLD_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011152));
#endif
    return fapi2::putScom(i_target, NX_CH4_GZIP_ERRRPT_HOLD_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_CH4_GZIP_ERRRPT_HOLD_REG_GZIP_ERRRPT_HOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011152));
#endif
    return o_data.insertFromRight<NX_CH4_GZIP_ERRRPT_HOLD_REG_GZIP_ERRRPT_HOLD,
           NX_CH4_GZIP_ERRRPT_HOLD_REG_GZIP_ERRRPT_HOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_ERRRPT_HOLD_REG_GZIP_ERRRPT_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_GZIP_ERRRPT_HOLD_REG_GZIP_ERRRPT_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011152));
#endif
    return o_data.insertFromRight<NX_CH4_GZIP_ERRRPT_HOLD_REG_GZIP_ERRRPT_HOLD,
           NX_CH4_GZIP_ERRRPT_HOLD_REG_GZIP_ERRRPT_HOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_ERRRPT_HOLD_REG_GZIP_ERRRPT_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_GZIP_ERRRPT_HOLD_REG_GZIP_ERRRPT_HOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011152));
#endif
    return i_data.extractToRight<NX_CH4_GZIP_ERRRPT_HOLD_REG_GZIP_ERRRPT_HOLD,
           NX_CH4_GZIP_ERRRPT_HOLD_REG_GZIP_ERRRPT_HOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_GZIP_ERRRPT_HOLD_REG_GZIP_ERRRPT_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_DBG_DEBUGMUX_CTRL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201110a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_DBG_DEBUGMUX_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201110a;
#endif
    return fapi2::getScom(i_target, NX_DBG_DEBUGMUX_CTRL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_DBG_DEBUGMUX_CTRL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201110a));
#endif
    return fapi2::putScom(i_target, NX_DBG_DEBUGMUX_CTRL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_DBG_DEBUGMUX_CTRL_NX_DEBUGMUX_CTRL_BITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201110a));
#endif
    return o_data.insertFromRight<NX_DBG_DEBUGMUX_CTRL_NX_DEBUGMUX_CTRL_BITS,
           NX_DBG_DEBUGMUX_CTRL_NX_DEBUGMUX_CTRL_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DBG_DEBUGMUX_CTRL_NX_DEBUGMUX_CTRL_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DBG_DEBUGMUX_CTRL_NX_DEBUGMUX_CTRL_BITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201110a));
#endif
    return o_data.insertFromRight<NX_DBG_DEBUGMUX_CTRL_NX_DEBUGMUX_CTRL_BITS,
           NX_DBG_DEBUGMUX_CTRL_NX_DEBUGMUX_CTRL_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DBG_DEBUGMUX_CTRL_NX_DEBUGMUX_CTRL_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DBG_DEBUGMUX_CTRL_NX_DEBUGMUX_CTRL_BITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201110a));
#endif
    return i_data.extractToRight<NX_DBG_DEBUGMUX_CTRL_NX_DEBUGMUX_CTRL_BITS,
           NX_DBG_DEBUGMUX_CTRL_NX_DEBUGMUX_CTRL_BITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DBG_DEBUGMUX_CTRL_NX_DEBUGMUX_CTRL_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_DMA_SU_PERFMON_CONTROL_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011054;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_DMA_SU_PERFMON_CONTROL_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011054;
#endif
    return fapi2::getScom(i_target, NX_DMA_SU_PERFMON_CONTROL_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_DMA_SU_PERFMON_CONTROL_0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011054));
#endif
    return fapi2::putScom(i_target, NX_DMA_SU_PERFMON_CONTROL_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_0_LPID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011054));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_0_LPID,
           NX_DMA_SU_PERFMON_CONTROL_0_LPID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_0_LPID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_0_LPID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011054));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_0_LPID,
           NX_DMA_SU_PERFMON_CONTROL_0_LPID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_0_LPID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_0_LPID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011054));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_0_LPID,
           NX_DMA_SU_PERFMON_CONTROL_0_LPID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_0_LPID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_0_LPID_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011054));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_0_LPID_MASK,
           NX_DMA_SU_PERFMON_CONTROL_0_LPID_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_0_LPID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_0_LPID_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011054));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_0_LPID_MASK,
           NX_DMA_SU_PERFMON_CONTROL_0_LPID_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_0_LPID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_0_LPID_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011054));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_0_LPID_MASK,
           NX_DMA_SU_PERFMON_CONTROL_0_LPID_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_0_LPID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_0_PID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011054));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_0_PID,
           NX_DMA_SU_PERFMON_CONTROL_0_PID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_0_PID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_0_PID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011054));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_0_PID,
           NX_DMA_SU_PERFMON_CONTROL_0_PID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_0_PID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_0_PID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011054));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_0_PID,
           NX_DMA_SU_PERFMON_CONTROL_0_PID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_0_PID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_0_PID_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011054));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_0_PID_MASK,
           NX_DMA_SU_PERFMON_CONTROL_0_PID_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_0_PID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_0_PID_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011054));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_0_PID_MASK,
           NX_DMA_SU_PERFMON_CONTROL_0_PID_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_0_PID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_0_PID_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011054));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_0_PID_MASK,
           NX_DMA_SU_PERFMON_CONTROL_0_PID_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_0_PID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_MAILBOX_30_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011836;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_MAILBOX_30_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011836;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_MAILBOX_30_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_MAILBOX_30_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10011836));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_MAILBOX_30_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_MAILBOX_31_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011837;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_MAILBOX_31_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011837;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_MAILBOX_31_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_MAILBOX_31_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10011837));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_MAILBOX_31_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PSAVE01_MISC_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011815;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PSAVE01_MISC_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011815;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PSAVE01_MISC_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PSAVE01_MISC_CFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PSAVE01_MISC_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUC,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUC,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUC,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUC,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUC,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUC,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUT,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUT,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUT,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUT,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUT,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUT,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_SPARE,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_SPARE,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_SPARE,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_HALF_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUC,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUC,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUC,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUC,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUC,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUC,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUT,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUT,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUT,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUT,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUT,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUT,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_SPARE,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_SPARE,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_SPARE,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_QTR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_WSIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_WSIZE,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_WSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_WSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE01_MISC_CFG_WSIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_WSIZE,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_WSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_WSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PSAVE01_MISC_CFG_WSIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PSAVE01_MISC_CFG_WSIZE,
           PB_PTLSCOM10_PSAVE01_MISC_CFG_WSIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE01_MISC_CFG_WSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PTL_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011806;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PTL_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011806;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PTL_FIR_ACTION0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PTL_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10011806));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PTL_FIR_ACTION0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011806));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0,
           PB_PTLSCOM10_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011806));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0,
           PB_PTLSCOM10_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011806));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0,
           PB_PTLSCOM10_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PTL_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011807;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PTL_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011807;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PTL_FIR_ACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PTL_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10011807));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PTL_FIR_ACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011807));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1,
           PB_PTLSCOM10_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011807));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1,
           PB_PTLSCOM10_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011807));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1,
           PB_PTLSCOM10_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_FM0123_ERR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011827;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_FM0123_ERR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011827;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_FM0123_ERR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_FM0123_ERR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x11011827));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_FM0123_ERR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_MAILBOX_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1101182f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_MAILBOX_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1101182f;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_MAILBOX_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_MAILBOX_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1101182f));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_MAILBOX_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_TL_LINK_SYN_01_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011812;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_TL_LINK_SYN_01_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011812;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_TL_LINK_SYN_01_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_TL_LINK_SYN_01_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x11011812));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_TL_LINK_SYN_01_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_CNPM_PMU_PRESCALER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011820;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011820;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_CNPM_PMU_PRESCALER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_CNPM_PMU_PRESCALER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_CNPM_PMU_PRESCALER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3,
           PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_MAILBOX_20_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011834;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_MAILBOX_20_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011834;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_MAILBOX_20_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_MAILBOX_20_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x12011834));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_MAILBOX_20_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_MAILBOX_21_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011835;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_MAILBOX_21_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011835;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_MAILBOX_21_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_MAILBOX_21_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x12011835));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_MAILBOX_21_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PMU3_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1201181e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PMU3_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1201181e;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PMU3_TLPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PMU3_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1201181e));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PMU3_TLPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PSAVE23_MODE_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011816;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PSAVE23_MODE_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011816;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PSAVE23_MODE_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PSAVE23_MODE_CFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x12011816));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PSAVE23_MODE_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE23_MODE_CFG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE23_MODE_CFG_MODE,
           PB_PTLSCOM45_PSAVE23_MODE_CFG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE23_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE23_MODE_CFG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE23_MODE_CFG_MODE,
           PB_PTLSCOM45_PSAVE23_MODE_CFG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE23_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PSAVE23_MODE_CFG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011816));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PSAVE23_MODE_CFG_MODE,
           PB_PTLSCOM45_PSAVE23_MODE_CFG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE23_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE23_MODE_CFG_WIDTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE23_MODE_CFG_WIDTH,
           PB_PTLSCOM45_PSAVE23_MODE_CFG_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE23_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE23_MODE_CFG_WIDTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE23_MODE_CFG_WIDTH,
           PB_PTLSCOM45_PSAVE23_MODE_CFG_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE23_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PSAVE23_MODE_CFG_WIDTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011816));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PSAVE23_MODE_CFG_WIDTH,
           PB_PTLSCOM45_PSAVE23_MODE_CFG_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE23_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE23_MODE_CFG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE23_MODE_CFG_SPARE,
           PB_PTLSCOM45_PSAVE23_MODE_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE23_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE23_MODE_CFG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE23_MODE_CFG_SPARE,
           PB_PTLSCOM45_PSAVE23_MODE_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE23_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PSAVE23_MODE_CFG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011816));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PSAVE23_MODE_CFG_SPARE,
           PB_PTLSCOM45_PSAVE23_MODE_CFG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE23_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE23_MODE_CFG_MIN_RAND_UC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE23_MODE_CFG_MIN_RAND_UC,
           PB_PTLSCOM45_PSAVE23_MODE_CFG_MIN_RAND_UC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE23_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE23_MODE_CFG_MIN_RAND_UC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE23_MODE_CFG_MIN_RAND_UC,
           PB_PTLSCOM45_PSAVE23_MODE_CFG_MIN_RAND_UC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE23_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PSAVE23_MODE_CFG_MIN_RAND_UC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011816));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PSAVE23_MODE_CFG_MIN_RAND_UC,
           PB_PTLSCOM45_PSAVE23_MODE_CFG_MIN_RAND_UC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE23_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_DOB01_DIB01_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011828;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_DOB01_DIB01_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011828;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_DOB01_DIB01_INT_ERR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_DOB01_DIB01_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x13011828));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_DOB01_DIB01_INT_ERR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_PMU0_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011821;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_PMU0_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011821;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_PMU0_CNPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_PMU0_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x13011821));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_PMU0_CNPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_HCA_FIR_ACTION1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3012407;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_HCA_FIR_ACTION1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3012407;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_HCA_FIR_ACTION1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_HCA_FIR_ACTION1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3012407));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_HCA_FIR_ACTION1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_FIR_ACTION1_FIR_ACTION1_BITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3012407));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_FIR_ACTION1_FIR_ACTION1_BITS,
           PB_BRIDGE_HCA_FIR_ACTION1_FIR_ACTION1_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_FIR_ACTION1_FIR_ACTION1_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_FIR_ACTION1_FIR_ACTION1_BITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3012407));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_FIR_ACTION1_FIR_ACTION1_BITS,
           PB_BRIDGE_HCA_FIR_ACTION1_FIR_ACTION1_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_FIR_ACTION1_FIR_ACTION1_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_FIR_ACTION1_FIR_ACTION1_BITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3012407));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_FIR_ACTION1_FIR_ACTION1_BITS,
           PB_BRIDGE_HCA_FIR_ACTION1_FIR_ACTION1_BITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_FIR_ACTION1_FIR_ACTION1_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x301240f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x301240f;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x301240f));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG_MONITOR_0_COUNTER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240f));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG_MONITOR_0_COUNTER,
           PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG_MONITOR_0_COUNTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG_MONITOR_0_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG_MONITOR_0_COUNTER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240f));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG_MONITOR_0_COUNTER,
           PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG_MONITOR_0_COUNTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG_MONITOR_0_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG_MONITOR_0_COUNTER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240f));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG_MONITOR_0_COUNTER,
           PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG_MONITOR_0_COUNTER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG_MONITOR_0_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_HCA_STATUS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x301240c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_HCA_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x301240c;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_HCA_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_HCA_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x301240c));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_HCA_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_STATUS_REG_RCMD_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240c));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_STATUS_REG_RCMD_BUSY,
           PB_BRIDGE_HCA_STATUS_REG_RCMD_BUSY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_STATUS_REG_RCMD_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_STATUS_REG_RCMD_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240c));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_STATUS_REG_RCMD_BUSY,
           PB_BRIDGE_HCA_STATUS_REG_RCMD_BUSY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_STATUS_REG_RCMD_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_STATUS_REG_RCMD_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240c));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_STATUS_REG_RCMD_BUSY,
           PB_BRIDGE_HCA_STATUS_REG_RCMD_BUSY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_STATUS_REG_RCMD_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_STATUS_REG_DECAY_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240c));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_STATUS_REG_DECAY_PENDING,
           PB_BRIDGE_HCA_STATUS_REG_DECAY_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_STATUS_REG_DECAY_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_STATUS_REG_DECAY_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240c));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_STATUS_REG_DECAY_PENDING,
           PB_BRIDGE_HCA_STATUS_REG_DECAY_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_STATUS_REG_DECAY_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_STATUS_REG_DECAY_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240c));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_STATUS_REG_DECAY_PENDING,
           PB_BRIDGE_HCA_STATUS_REG_DECAY_PENDING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_STATUS_REG_DECAY_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240c));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240c));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240c));
#endif
    return o_data.setBit<PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240c));
#endif
    return o_data.clearBit<PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240c));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240c));
#endif
    return i_data.getBit<PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_STATUS_REG_PBI_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_STATUS_REG_INVALIDATE_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240c));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_STATUS_REG_INVALIDATE_BUSY,
           PB_BRIDGE_HCA_STATUS_REG_INVALIDATE_BUSY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_STATUS_REG_INVALIDATE_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_STATUS_REG_INVALIDATE_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240c));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_STATUS_REG_INVALIDATE_BUSY,
           PB_BRIDGE_HCA_STATUS_REG_INVALIDATE_BUSY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_STATUS_REG_INVALIDATE_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_STATUS_REG_INVALIDATE_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301240c));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_STATUS_REG_INVALIDATE_BUSY,
           PB_BRIDGE_HCA_STATUS_REG_INVALIDATE_BUSY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_STATUS_REG_INVALIDATE_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x30120c9;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x30120c9;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL0,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL0,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL0,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL1,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL1,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL1,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL2,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL2,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL2,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL3,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL3,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL3,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL4,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL4,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL4,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL5,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL5,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL5,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_RGRPSEL5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL0,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL0,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL0,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL1,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL1,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL1,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL2,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL2,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c9));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL2,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX_CGRPSEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x30120c0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x30120c0;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CONTENT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CONTENT_SEL,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CONTENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CONTENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CONTENT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CONTENT_SEL,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CONTENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CONTENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CONTENT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CONTENT_SEL,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CONTENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CONTENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CAPTURE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CAPTURE,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CAPTURE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CAPTURE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CAPTURE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CAPTURE,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CAPTURE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CAPTURE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CAPTURE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CAPTURE,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CAPTURE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_CAPTURE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SYNC_STAMP_FORCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SYNC_STAMP_FORCE,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SYNC_STAMP_FORCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SYNC_STAMP_FORCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SYNC_STAMP_FORCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SYNC_STAMP_FORCE,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SYNC_STAMP_FORCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SYNC_STAMP_FORCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SYNC_STAMP_FORCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SYNC_STAMP_FORCE,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SYNC_STAMP_FORCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SYNC_STAMP_FORCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_VGTARGET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_VGTARGET,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_VGTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_VGTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_VGTARGET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_VGTARGET,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_VGTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_VGTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_VGTARGET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_VGTARGET,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_VGTARGET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_VGTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE4043(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE4043,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE4043_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE4043 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE4043(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE4043,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE4043_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE4043 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE4043(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c0));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE4043,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE4043_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE_SPARE4043 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRWOF_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011888;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRWOF_REG(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011888;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRWOF_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRWOF_REG(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011888));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRWOF_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011897;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011897;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011897));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011896;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011896;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_FV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011896));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_PE_SPARSE_PAGE_CNTL_REG_T4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010908;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010908;
#endif
    return fapi2::getScom(i_target, PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return fapi2::putScom(i_target, PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010909;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010909;
#endif
    return fapi2::getScom(i_target, PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return fapi2::putScom(i_target, PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x801090a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x801090a;
#endif
    return fapi2::getScom(i_target, PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return fapi2::putScom(i_target, PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_COMMAND_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ADDRESS_INVALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_OUTBOUND_INJECT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_FATAL_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_AIB_INF_CLASS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PE_STOP_STATE_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_ARRAY_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LATCH_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_COMMON_LOGIC_FATAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_BLIF_OUT_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_WRITE_CA_OR_UR_RESPONSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MMIO_REQUEST_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_OUT_RRB_SOURCED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_CFG_LOGIC_SIGNALED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_REG_REQUEST_ADDRESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDA_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_FDB_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_ERR_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_DBG_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_REQUEST_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_BUS_LOGIC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_RSB_UVI_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_SCOM_INF_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_IODA_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_PE_MATCH_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_MSI_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TVT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_FATAL_ERROR_MSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_NONFATAL_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_PAPR_INBOUND_INJECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_BLIF_COMPLETION_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_PCT_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_TLP_POISON_SIGNALED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_ARB_RTT_PENUM_INVALID_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_TABLE_BAR_DISABLED_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_AIB2_TX_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_MRG_MRT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_IODA_PAGE_ACCESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_REQUEST_TIMEOUT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_UNEXPECTED_RESPONSE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_COMMON_FATAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_CORRECTABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_TCE_ECC_UNCORRECTABLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801090a, 0x8010909, 0x8010908));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_FIR_REG_FIR_INTERNAL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


}
}

#endif
