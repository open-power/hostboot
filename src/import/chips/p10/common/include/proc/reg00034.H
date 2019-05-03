/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00034.H $         */
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

#ifndef __PROC_REG00034_H_
#define __PROC_REG00034_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_NVC_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_NVC_BAR;
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
    scomt::last_scom = INT_CQ_NVC_BAR;
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_NVC_BAR));
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
    scomt::last_scom = INT_CQ_PMC_3;
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
    scomt::last_scom = INT_CQ_PMC_3;
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
    FAPI_TRY(scomt::chkReg(INT_CQ_PMC_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_PMC_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_PMC_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_PMC_3));
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
    scomt::last_scom = INT_CQ_TTT_3;
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
    scomt::last_scom = INT_CQ_TTT_3;
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    FAPI_TRY(scomt::chkReg(INT_CQ_TTT_3));
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
    scomt::last_scom = INT_PC_NXC_REGS_INFO_ERR;
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
    scomt::last_scom = INT_PC_NXC_REGS_INFO_ERR;
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
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_INFO_ERR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_INFO_ERR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_INFO_ERR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_INFO_ERR));
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
    scomt::last_scom = INT_PC_NXC_REGS_WATCH0_DATA3;
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
    scomt::last_scom = INT_PC_NXC_REGS_WATCH0_DATA3;
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
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WATCH0_DATA3));
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
    scomt::last_scom = INT_PC_NXC_REGS_WATCH1_SPEC;
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
    scomt::last_scom = INT_PC_NXC_REGS_WATCH1_SPEC;
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
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WATCH1_SPEC));
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
    scomt::last_scom = INT_PC_REGS_AIB_RX_CRD_DAT;
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
    scomt::last_scom = INT_PC_REGS_AIB_RX_CRD_DAT;
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AIB_RX_CRD_DAT));
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
    scomt::last_scom = INT_PC_REGS_ERR0_WOF_DETAIL;
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
    scomt::last_scom = INT_PC_REGS_ERR0_WOF_DETAIL;
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_ERR0_WOF_DETAIL));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_ERR0_WOF_DETAIL));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_ERR0_WOF_DETAIL));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_ERR0_WOF_DETAIL));
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
    scomt::last_scom = INT_PC_REGS_TCTXT_DEBUG_ADDR;
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
    scomt::last_scom = INT_PC_REGS_TCTXT_DEBUG_ADDR;
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_DEBUG_ADDR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_DEBUG_ADDR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_DEBUG_ADDR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_DEBUG_ADDR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_DEBUG_ADDR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_DEBUG_ADDR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_DEBUG_ADDR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_DEBUG_ADDR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_DEBUG_ADDR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_DEBUG_ADDR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_DEBUG_ADDR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_DEBUG_ADDR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_DEBUG_ADDR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_DEBUG_ADDR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_DEBUG_ADDR));
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
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_DEBUG_ADDR));
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
    scomt::last_scom = INT_VC_EASC_DBG;
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
    scomt::last_scom = INT_VC_EASC_DBG;
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_DBG));
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
    scomt::last_scom = INT_VC_EASC_HASH_2;
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
    scomt::last_scom = INT_VC_EASC_HASH_2;
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_HASH_2));
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
    scomt::last_scom = INT_VC_EASC_PERF_EVENT_SEL_3;
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
    scomt::last_scom = INT_VC_EASC_PERF_EVENT_SEL_3;
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_PERF_EVENT_SEL_3));
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
    scomt::last_scom = INT_VC_ENDC_PERF_EVENT_SEL_3;
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
    scomt::last_scom = INT_VC_ENDC_PERF_EVENT_SEL_3;
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_3));
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
    scomt::last_scom = INT_VC_ENDC_WATCH3_DATA1;
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
    scomt::last_scom = INT_VC_ENDC_WATCH3_DATA1;
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
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH3_DATA1));
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
    scomt::last_scom = INT_VC_QUEUES_CFG_REM_4;
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
    scomt::last_scom = INT_VC_QUEUES_CFG_REM_4;
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_4));
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
    scomt::last_scom = INT_VC_QUEUES_PERF_EVENT_SEL_7;
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
    scomt::last_scom = INT_VC_QUEUES_PERF_EVENT_SEL_7;
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_7));
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
    scomt::last_scom = MCD_BANK0_CHA;
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
    scomt::last_scom = MCD_BANK0_CHA;
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_CHA));
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
    scomt::last_scom = MCD_BANK0_TOP;
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
    scomt::last_scom = MCD_BANK0_TOP;
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
    FAPI_TRY(scomt::chkReg(MCD_BANK0_TOP));
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
static inline fapi2::ReturnCode PREP_NX_CH4_GZIP_ERRRPT_HOLD_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_CH4_GZIP_ERRRPT_HOLD_REG;
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
    scomt::last_scom = NX_CH4_GZIP_ERRRPT_HOLD_REG;
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
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_ERRRPT_HOLD_REG));
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
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_ERRRPT_HOLD_REG));
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
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_ERRRPT_HOLD_REG));
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
    FAPI_TRY(scomt::chkReg(NX_CH4_GZIP_ERRRPT_HOLD_REG));
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
    scomt::last_scom = NX_DBG_DEBUGMUX_CTRL;
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
    scomt::last_scom = NX_DBG_DEBUGMUX_CTRL;
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
    FAPI_TRY(scomt::chkReg(NX_DBG_DEBUGMUX_CTRL));
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
    FAPI_TRY(scomt::chkReg(NX_DBG_DEBUGMUX_CTRL));
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
    FAPI_TRY(scomt::chkReg(NX_DBG_DEBUGMUX_CTRL));
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
    FAPI_TRY(scomt::chkReg(NX_DBG_DEBUGMUX_CTRL));
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
    scomt::last_scom = NX_DMA_SU_PERFMON_CONTROL_0;
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
    scomt::last_scom = NX_DMA_SU_PERFMON_CONTROL_0;
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
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_PERFMON_CONTROL_0));
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
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_PERFMON_CONTROL_0));
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
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_PERFMON_CONTROL_0));
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
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_PERFMON_CONTROL_0));
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
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_PERFMON_CONTROL_0));
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
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_PERFMON_CONTROL_0));
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
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_PERFMON_CONTROL_0));
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
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_PERFMON_CONTROL_0));
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
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_PERFMON_CONTROL_0));
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
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_PERFMON_CONTROL_0));
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
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_PERFMON_CONTROL_0));
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
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_PERFMON_CONTROL_0));
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
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_PERFMON_CONTROL_0));
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
    scomt::last_scom = PB_PTLSCOM10_MAILBOX_30_REG;
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
    scomt::last_scom = PB_PTLSCOM10_MAILBOX_30_REG;
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MAILBOX_30_REG));
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
    scomt::last_scom = PB_PTLSCOM10_MAILBOX_31_REG;
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
    scomt::last_scom = PB_PTLSCOM10_MAILBOX_31_REG;
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MAILBOX_31_REG));
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
    scomt::last_scom = PB_PTLSCOM10_PSAVE01_MISC_CFG;
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
    scomt::last_scom = PB_PTLSCOM10_PSAVE01_MISC_CFG;
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PSAVE01_MISC_CFG));
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
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_ACTION0_REG;
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
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_ACTION0_REG;
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_ACTION0_REG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_ACTION0_REG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_ACTION0_REG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_ACTION0_REG));
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
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_ACTION1_REG;
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
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_ACTION1_REG;
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_ACTION1_REG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_ACTION1_REG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_ACTION1_REG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_ACTION1_REG));
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
    scomt::last_scom = PB_PTLSCOM23_FM0123_ERR;
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
    scomt::last_scom = PB_PTLSCOM23_FM0123_ERR;
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_FM0123_ERR));
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
    scomt::last_scom = PB_PTLSCOM23_MAILBOX_DATA_REG;
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
    scomt::last_scom = PB_PTLSCOM23_MAILBOX_DATA_REG;
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_MAILBOX_DATA_REG));
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
    scomt::last_scom = PB_PTLSCOM23_TL_LINK_SYN_01_REG;
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
    scomt::last_scom = PB_PTLSCOM23_TL_LINK_SYN_01_REG;
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_SYN_01_REG));
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
    scomt::last_scom = PB_PTLSCOM45_CNPM_PMU_PRESCALER;
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
    scomt::last_scom = PB_PTLSCOM45_CNPM_PMU_PRESCALER;
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CNPM_PMU_PRESCALER));
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
    scomt::last_scom = PB_PTLSCOM45_MAILBOX_20_REG;
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
    scomt::last_scom = PB_PTLSCOM45_MAILBOX_20_REG;
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_MAILBOX_20_REG));
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
    scomt::last_scom = PB_PTLSCOM45_MAILBOX_21_REG;
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
    scomt::last_scom = PB_PTLSCOM45_MAILBOX_21_REG;
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_MAILBOX_21_REG));
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
    scomt::last_scom = PB_PTLSCOM45_PMU3_TLPM_COUNTER;
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
    scomt::last_scom = PB_PTLSCOM45_PMU3_TLPM_COUNTER;
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PMU3_TLPM_COUNTER));
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
    scomt::last_scom = PB_PTLSCOM45_PSAVE23_MODE_CFG;
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
    scomt::last_scom = PB_PTLSCOM45_PSAVE23_MODE_CFG;
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PSAVE23_MODE_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PSAVE23_MODE_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PSAVE23_MODE_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PSAVE23_MODE_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PSAVE23_MODE_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PSAVE23_MODE_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PSAVE23_MODE_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PSAVE23_MODE_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PSAVE23_MODE_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PSAVE23_MODE_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PSAVE23_MODE_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PSAVE23_MODE_CFG));
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PSAVE23_MODE_CFG));
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
    scomt::last_scom = PB_PTLSCOM67_DOB01_DIB01_INT_ERR_REG;
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
    scomt::last_scom = PB_PTLSCOM67_DOB01_DIB01_INT_ERR_REG;
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_DOB01_DIB01_INT_ERR_REG));
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
    scomt::last_scom = PB_PTLSCOM67_PMU0_CNPM_COUNTER;
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
    scomt::last_scom = PB_PTLSCOM67_PMU0_CNPM_COUNTER;
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
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PMU0_CNPM_COUNTER));
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
    scomt::last_scom = PB_BRIDGE_HCA_FIR_ACTION1;
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
    scomt::last_scom = PB_BRIDGE_HCA_FIR_ACTION1;
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_FIR_ACTION1));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_FIR_ACTION1));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_FIR_ACTION1));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_FIR_ACTION1));
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
    scomt::last_scom = PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG;
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
    scomt::last_scom = PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG;
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_MONITOR_0_COUNTER_REG));
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
    scomt::last_scom = PB_BRIDGE_HCA_STATUS_REG;
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
    scomt::last_scom = PB_BRIDGE_HCA_STATUS_REG;
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_STATUS_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_STATUS_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_STATUS_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_STATUS_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_STATUS_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_STATUS_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_STATUS_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_STATUS_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_STATUS_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_STATUS_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_STATUS_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_STATUS_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_STATUS_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_STATUS_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_STATUS_REG));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_STATUS_REG));
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
    scomt::last_scom = PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX;
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
    scomt::last_scom = PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX;
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_FLEX));
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
    scomt::last_scom = PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE;
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
    scomt::last_scom = PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE;
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_MODE));
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
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_CLOCK_STAT_SL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_CLOCK_STAT_SL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_CLOCK_STAT_SL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_CLOCK_STAT_SL;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_CLOCK_STAT_SL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_CLOCK_STAT_SL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_CLOCK_STAT_SL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_CPLT_CTRL3_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_CPLT_CTRL3_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_CPLT_CTRL3_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_CPLT_CTRL3_RW;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_CPLT_CTRL3_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_CPLT_CTRL3_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_CPLT_CTRL3_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_CPLT_CTRL3_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_CPLT_CTRL3_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_CPLT_CTRL3_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_CPLT_CTRL3_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_CPLT_CTRL3_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_CPLT_CTRL3_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_CPLT_CTRL3_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CPLT_CTRL3_RW, TP_TCN0_N0_CPLT_CTRL3_WO_CLEAR, TP_TCN0_N0_CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT,
           TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT,
           TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT,
           TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT,
           TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT,
           TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT,
           TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT,
           TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT,
           TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT,
           TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_LOCAL_XSTOP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_LOCAL_XSTOP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_LOCAL_XSTOP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_LOCAL_XSTOP;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_LOCAL_XSTOP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_LOCAL_XSTOP(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_LOCAL_XSTOP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.setBit<TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.clearBit<TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.extractToRight<TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.getBit<TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.setBit<TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.clearBit<TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.extractToRight<TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.getBit<TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.setBit<TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.clearBit<TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.extractToRight<TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.getBit<TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.setBit<TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.clearBit<TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.extractToRight<TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.getBit<TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.setBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.clearBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.extractToRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.getBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.setBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.clearBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.extractToRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.getBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.setBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.clearBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.extractToRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.getBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.setBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.clearBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.extractToRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.getBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.setBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.clearBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.extractToRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.getBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.setBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.clearBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.extractToRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.getBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.setBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.clearBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.extractToRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.getBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.setBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.clearBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.extractToRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.getBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.setBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.clearBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.extractToRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.getBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.setBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.clearBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.extractToRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.getBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.setBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.clearBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.extractToRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.getBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.setBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return o_data.clearBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.extractToRight<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_LOCAL_XSTOP));
#endif
    return i_data.getBit<TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_LOCAL_XSTOP_LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_SPATTN_MASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_SPATTN_MASK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_SPATTN_MASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_SPATTN_MASK;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_SPATTN_MASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_SPATTN_MASK(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_SPATTN_MASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_SPATTN_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_SPATTN_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.setBit<TP_TCN0_N0_SPATTN_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_SPATTN_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return o_data.clearBit<TP_TCN0_N0_SPATTN_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_SPATTN_MASK_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.extractToRight<TP_TCN0_N0_SPATTN_MASK_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_SPATTN_MASK_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_SPATTN_MASK));
#endif
    return i_data.getBit<TP_TCN0_N0_SPATTN_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_TRA0_TR1_CONFIG_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_TRA0_TR1_CONFIG_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_TRA0_TR1_CONFIG_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_TRA0_TR1_CONFIG_1;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_TRA0_TR1_CONFIG_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_TRA0_TR1_CONFIG_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR1_CONFIG_1));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_TRA0_TR1_CONFIG_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR1_CONFIG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           TP_TCN0_N0_TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR1_CONFIG_1));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           TP_TCN0_N0_TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR1_CONFIG_1));
#endif
    return i_data.extractToRight<TP_TCN0_N0_TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           TP_TCN0_N0_TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


}
}

#endif
