/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00054.H $         */
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

#ifndef __PROC_REG00054_H_
#define __PROC_REG00054_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_PMC_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201082a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_PMC_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201082a;
#endif
    return fapi2::getScom(i_target, INT_CQ_PMC_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_PMC_2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201082a));
#endif
    return fapi2::putScom(i_target, INT_CQ_PMC_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PMC_2_INT_CQ_PMC_2_COUNT_0_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201082a));
#endif
    return o_data.insertFromRight<INT_CQ_PMC_2_INT_CQ_PMC_2_COUNT_0_47,
           INT_CQ_PMC_2_INT_CQ_PMC_2_COUNT_0_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PMC_2_INT_CQ_PMC_2_COUNT_0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PMC_2_INT_CQ_PMC_2_COUNT_0_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201082a));
#endif
    return o_data.insertFromRight<INT_CQ_PMC_2_INT_CQ_PMC_2_COUNT_0_47,
           INT_CQ_PMC_2_INT_CQ_PMC_2_COUNT_0_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PMC_2_INT_CQ_PMC_2_COUNT_0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_PMC_2_INT_CQ_PMC_2_COUNT_0_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201082a));
#endif
    return i_data.extractToRight<INT_CQ_PMC_2_INT_CQ_PMC_2_COUNT_0_47,
           INT_CQ_PMC_2_INT_CQ_PMC_2_COUNT_0_47_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PMC_2_INT_CQ_PMC_2_COUNT_0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_TTT_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010806;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_TTT_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010806;
#endif
    return fapi2::getScom(i_target, INT_CQ_TTT_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_TTT_2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return fapi2::putScom(i_target, INT_CQ_TTT_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_VALID_0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_VALID_0_7,
           INT_CQ_TTT_2_VALID_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_VALID_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_VALID_0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_VALID_0_7,
           INT_CQ_TTT_2_VALID_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_VALID_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_2_VALID_0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return i_data.extractToRight<INT_CQ_TTT_2_VALID_0_7,
           INT_CQ_TTT_2_VALID_0_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_VALID_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_ENTRY_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_ENTRY_0_3,
           INT_CQ_TTT_2_ENTRY_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_ENTRY_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_ENTRY_0_3,
           INT_CQ_TTT_2_ENTRY_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_2_ENTRY_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return i_data.extractToRight<INT_CQ_TTT_2_ENTRY_0_3,
           INT_CQ_TTT_2_ENTRY_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_ENTRY_1_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_ENTRY_1_0_3,
           INT_CQ_TTT_2_ENTRY_1_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_1_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_ENTRY_1_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_ENTRY_1_0_3,
           INT_CQ_TTT_2_ENTRY_1_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_1_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_2_ENTRY_1_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return i_data.extractToRight<INT_CQ_TTT_2_ENTRY_1_0_3,
           INT_CQ_TTT_2_ENTRY_1_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_1_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_ENTRY_2_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_ENTRY_2_0_3,
           INT_CQ_TTT_2_ENTRY_2_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_2_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_ENTRY_2_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_ENTRY_2_0_3,
           INT_CQ_TTT_2_ENTRY_2_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_2_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_2_ENTRY_2_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return i_data.extractToRight<INT_CQ_TTT_2_ENTRY_2_0_3,
           INT_CQ_TTT_2_ENTRY_2_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_2_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_ENTRY_3_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_ENTRY_3_0,
           INT_CQ_TTT_2_ENTRY_3_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_ENTRY_3_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_ENTRY_3_0,
           INT_CQ_TTT_2_ENTRY_3_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_2_ENTRY_3_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return i_data.extractToRight<INT_CQ_TTT_2_ENTRY_3_0,
           INT_CQ_TTT_2_ENTRY_3_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_ENTRY_4_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_ENTRY_4_0_3,
           INT_CQ_TTT_2_ENTRY_4_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_4_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_ENTRY_4_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_ENTRY_4_0_3,
           INT_CQ_TTT_2_ENTRY_4_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_4_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_2_ENTRY_4_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return i_data.extractToRight<INT_CQ_TTT_2_ENTRY_4_0_3,
           INT_CQ_TTT_2_ENTRY_4_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_4_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_ENTRY_5_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_ENTRY_5_0_3,
           INT_CQ_TTT_2_ENTRY_5_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_5_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_ENTRY_5_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_ENTRY_5_0_3,
           INT_CQ_TTT_2_ENTRY_5_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_5_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_2_ENTRY_5_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return i_data.extractToRight<INT_CQ_TTT_2_ENTRY_5_0_3,
           INT_CQ_TTT_2_ENTRY_5_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_5_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_ENTRY_6_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_ENTRY_6_0_3,
           INT_CQ_TTT_2_ENTRY_6_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_6_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_ENTRY_6_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_ENTRY_6_0_3,
           INT_CQ_TTT_2_ENTRY_6_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_6_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_2_ENTRY_6_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return i_data.extractToRight<INT_CQ_TTT_2_ENTRY_6_0_3,
           INT_CQ_TTT_2_ENTRY_6_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_6_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_ENTRY_7_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_ENTRY_7_0_3,
           INT_CQ_TTT_2_ENTRY_7_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_7_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_TTT_2_ENTRY_7_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return o_data.insertFromRight<INT_CQ_TTT_2_ENTRY_7_0_3,
           INT_CQ_TTT_2_ENTRY_7_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_7_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_TTT_2_ENTRY_7_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010806));
#endif
    return i_data.extractToRight<INT_CQ_TTT_2_ENTRY_7_0_3,
           INT_CQ_TTT_2_ENTRY_7_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_TTT_2_ENTRY_7_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_XIVE_CAP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010802;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_XIVE_CAP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010802;
#endif
    return fapi2::getScom(i_target, INT_CQ_XIVE_CAP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_XIVE_CAP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010802));
#endif
    return fapi2::putScom(i_target, INT_CQ_XIVE_CAP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CAP_INT_CQ_XIVE_CAP_INFO_0_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010802));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CAP_INT_CQ_XIVE_CAP_INFO_0_63,
           INT_CQ_XIVE_CAP_INT_CQ_XIVE_CAP_INFO_0_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CAP_INT_CQ_XIVE_CAP_INFO_0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CAP_INT_CQ_XIVE_CAP_INFO_0_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010802));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CAP_INT_CQ_XIVE_CAP_INFO_0_63,
           INT_CQ_XIVE_CAP_INT_CQ_XIVE_CAP_INFO_0_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CAP_INT_CQ_XIVE_CAP_INFO_0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CAP_INT_CQ_XIVE_CAP_INFO_0_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010802));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CAP_INT_CQ_XIVE_CAP_INFO_0_63,
           INT_CQ_XIVE_CAP_INT_CQ_XIVE_CAP_INFO_0_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CAP_INT_CQ_XIVE_CAP_INFO_0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_XIVE_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010803;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_XIVE_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010803;
#endif
    return fapi2::getScom(i_target, INT_CQ_XIVE_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_XIVE_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return fapi2::putScom(i_target, INT_CQ_XIVE_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_0_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_RESERVED_0_5,
           INT_CQ_XIVE_CFG_RESERVED_0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_0_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_RESERVED_0_5,
           INT_CQ_XIVE_CFG_RESERVED_0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_RESERVED_0_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_RESERVED_0_5,
           INT_CQ_XIVE_CFG_RESERVED_0_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_HYP_HARD_RANGE_0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_HYP_HARD_RANGE_0_1,
           INT_CQ_XIVE_CFG_HYP_HARD_RANGE_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_HYP_HARD_RANGE_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_HYP_HARD_RANGE_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_HYP_HARD_RANGE_0_1,
           INT_CQ_XIVE_CFG_HYP_HARD_RANGE_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_HYP_HARD_RANGE_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_HYP_HARD_RANGE_0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_HYP_HARD_RANGE_0_1,
           INT_CQ_XIVE_CFG_HYP_HARD_RANGE_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_HYP_HARD_RANGE_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_8_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_RESERVED_8_9,
           INT_CQ_XIVE_CFG_RESERVED_8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_8_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_RESERVED_8_9,
           INT_CQ_XIVE_CFG_RESERVED_8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_RESERVED_8_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_RESERVED_8_9,
           INT_CQ_XIVE_CFG_RESERVED_8_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_INT_PRIORITIES_0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_INT_PRIORITIES_0_1,
           INT_CQ_XIVE_CFG_INT_PRIORITIES_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_INT_PRIORITIES_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_INT_PRIORITIES_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_INT_PRIORITIES_0_1,
           INT_CQ_XIVE_CFG_INT_PRIORITIES_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_INT_PRIORITIES_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_INT_PRIORITIES_0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_INT_PRIORITIES_0_1,
           INT_CQ_XIVE_CFG_INT_PRIORITIES_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_INT_PRIORITIES_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_12_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_RESERVED_12_13,
           INT_CQ_XIVE_CFG_RESERVED_12_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_12_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_12_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_RESERVED_12_13,
           INT_CQ_XIVE_CFG_RESERVED_12_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_12_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_RESERVED_12_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_RESERVED_12_13,
           INT_CQ_XIVE_CFG_RESERVED_12_13_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_12_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_BLOCKID_WIDTH_0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_BLOCKID_WIDTH_0_1,
           INT_CQ_XIVE_CFG_BLOCKID_WIDTH_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_BLOCKID_WIDTH_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_BLOCKID_WIDTH_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_BLOCKID_WIDTH_0_1,
           INT_CQ_XIVE_CFG_BLOCKID_WIDTH_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_BLOCKID_WIDTH_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_BLOCKID_WIDTH_0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_BLOCKID_WIDTH_0_1,
           INT_CQ_XIVE_CFG_BLOCKID_WIDTH_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_BLOCKID_WIDTH_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.setBit<INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.clearBit<INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.getBit<INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_HYP_HARD_BLKID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_HYP_HARD_BLKID_0_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_HYP_HARD_BLKID_0_6,
           INT_CQ_XIVE_CFG_HYP_HARD_BLKID_0_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_HYP_HARD_BLKID_0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_HYP_HARD_BLKID_0_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_HYP_HARD_BLKID_0_6,
           INT_CQ_XIVE_CFG_HYP_HARD_BLKID_0_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_HYP_HARD_BLKID_0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_HYP_HARD_BLKID_0_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_HYP_HARD_BLKID_0_6,
           INT_CQ_XIVE_CFG_HYP_HARD_BLKID_0_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_HYP_HARD_BLKID_0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_GEN1_TIMA_OS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_GEN1_TIMA_OS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_OS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_GEN1_TIMA_OS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_GEN1_TIMA_OS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_OS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_GEN1_TIMA_OS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.setBit<INT_CQ_XIVE_CFG_GEN1_TIMA_OS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_OS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_XIVE_CFG_GEN1_TIMA_OS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.clearBit<INT_CQ_XIVE_CFG_GEN1_TIMA_OS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_OS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_GEN1_TIMA_OS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_GEN1_TIMA_OS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_OS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_XIVE_CFG_GEN1_TIMA_OS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.getBit<INT_CQ_XIVE_CFG_GEN1_TIMA_OS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_OS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_GEN1_TIMA_HYP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_GEN1_TIMA_HYP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_HYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_GEN1_TIMA_HYP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_GEN1_TIMA_HYP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_HYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_GEN1_TIMA_HYP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.setBit<INT_CQ_XIVE_CFG_GEN1_TIMA_HYP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_HYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_XIVE_CFG_GEN1_TIMA_HYP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.clearBit<INT_CQ_XIVE_CFG_GEN1_TIMA_HYP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_HYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_GEN1_TIMA_HYP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_GEN1_TIMA_HYP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_HYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_XIVE_CFG_GEN1_TIMA_HYP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.getBit<INT_CQ_XIVE_CFG_GEN1_TIMA_HYP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_HYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.setBit<INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.clearBit<INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.getBit<INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_HYP_BLK0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.setBit<INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.clearBit<INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.getBit<INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_TIMA_CROWD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_GEN1_END_ESX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_GEN1_END_ESX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_END_ESX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_GEN1_END_ESX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_GEN1_END_ESX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_END_ESX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_GEN1_END_ESX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.setBit<INT_CQ_XIVE_CFG_GEN1_END_ESX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_END_ESX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_XIVE_CFG_GEN1_END_ESX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.clearBit<INT_CQ_XIVE_CFG_GEN1_END_ESX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_END_ESX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_GEN1_END_ESX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_GEN1_END_ESX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_END_ESX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_XIVE_CFG_GEN1_END_ESX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.getBit<INT_CQ_XIVE_CFG_GEN1_END_ESX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_GEN1_END_ESX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_29_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_RESERVED_29_31,
           INT_CQ_XIVE_CFG_RESERVED_29_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_29_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_29_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_RESERVED_29_31,
           INT_CQ_XIVE_CFG_RESERVED_29_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_29_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_RESERVED_29_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_RESERVED_29_31,
           INT_CQ_XIVE_CFG_RESERVED_29_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_29_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.setBit<INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.clearBit<INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.getBit<INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_EQPOST_INTERLEAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_RESERVED_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_RESERVED_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.setBit<INT_CQ_XIVE_CFG_RESERVED_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_XIVE_CFG_RESERVED_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.clearBit<INT_CQ_XIVE_CFG_RESERVED_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_RESERVED_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_RESERVED_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_XIVE_CFG_RESERVED_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.getBit<INT_CQ_XIVE_CFG_RESERVED_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.setBit<INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.clearBit<INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.getBit<INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_ADAP_ESC_VP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.setBit<INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.clearBit<INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.getBit<INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_ADAP_ESC_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_36_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_RESERVED_36_38,
           INT_CQ_XIVE_CFG_RESERVED_36_38_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_36_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_36_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_RESERVED_36_38,
           INT_CQ_XIVE_CFG_RESERVED_36_38_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_36_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_RESERVED_36_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_RESERVED_36_38,
           INT_CQ_XIVE_CFG_RESERVED_36_38_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_36_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.setBit<INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.clearBit<INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.getBit<INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_VP_SAVE_RESTORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_40_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_RESERVED_40_47,
           INT_CQ_XIVE_CFG_RESERVED_40_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_40_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_40_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_RESERVED_40_47,
           INT_CQ_XIVE_CFG_RESERVED_40_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_40_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_RESERVED_40_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_RESERVED_40_47,
           INT_CQ_XIVE_CFG_RESERVED_40_47_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_40_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.setBit<INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.clearBit<INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.getBit<INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_EN_HYP_SECURE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_49_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_RESERVED_49_63,
           INT_CQ_XIVE_CFG_RESERVED_49_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_49_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_XIVE_CFG_RESERVED_49_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return o_data.insertFromRight<INT_CQ_XIVE_CFG_RESERVED_49_63,
           INT_CQ_XIVE_CFG_RESERVED_49_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_49_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_XIVE_CFG_RESERVED_49_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010803));
#endif
    return i_data.extractToRight<INT_CQ_XIVE_CFG_RESERVED_49_63,
           INT_CQ_XIVE_CFG_RESERVED_49_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_XIVE_CFG_RESERVED_49_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_CACHE_EN(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a95;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_CACHE_EN(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a95;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_CACHE_EN, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_CACHE_EN(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010a95));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_CACHE_EN, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CACHE_EN_P_CACHE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a95));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CACHE_EN_P_CACHE_ENABLE,
           INT_PC_NXC_REGS_CACHE_EN_P_CACHE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CACHE_EN_P_CACHE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CACHE_EN_P_CACHE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a95));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CACHE_EN_P_CACHE_ENABLE,
           INT_PC_NXC_REGS_CACHE_EN_P_CACHE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CACHE_EN_P_CACHE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CACHE_EN_P_CACHE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a95));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CACHE_EN_P_CACHE_ENABLE,
           INT_PC_NXC_REGS_CACHE_EN_P_CACHE_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CACHE_EN_P_CACHE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CACHE_EN_G_CACHE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a95));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CACHE_EN_G_CACHE_ENABLE,
           INT_PC_NXC_REGS_CACHE_EN_G_CACHE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CACHE_EN_G_CACHE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CACHE_EN_G_CACHE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a95));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CACHE_EN_G_CACHE_ENABLE,
           INT_PC_NXC_REGS_CACHE_EN_G_CACHE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CACHE_EN_G_CACHE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CACHE_EN_G_CACHE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a95));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CACHE_EN_G_CACHE_ENABLE,
           INT_PC_NXC_REGS_CACHE_EN_G_CACHE_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CACHE_EN_G_CACHE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CACHE_EN_C_CACHE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a95));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CACHE_EN_C_CACHE_ENABLE,
           INT_PC_NXC_REGS_CACHE_EN_C_CACHE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CACHE_EN_C_CACHE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CACHE_EN_C_CACHE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a95));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CACHE_EN_C_CACHE_ENABLE,
           INT_PC_NXC_REGS_CACHE_EN_C_CACHE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CACHE_EN_C_CACHE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CACHE_EN_C_CACHE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a95));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CACHE_EN_C_CACHE_ENABLE,
           INT_PC_NXC_REGS_CACHE_EN_C_CACHE_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CACHE_EN_C_CACHE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_LOAD_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a8b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_LOAD_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a8b;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_LOAD_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_LOAD_CONFIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_LOAD_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_NCKO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_NCKO,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_NCKO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_NCKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_NCKO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_NCKO,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_NCKO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_NCKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_NCKO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_NCKO,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_NCKO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_NCKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_CHKO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_CHKO,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_CHKO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_CHKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_CHKO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_CHKO,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_CHKO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_CHKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_CHKO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_CHKO,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_CHKO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_QUEUE_SIZE_CHKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_RSVD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_RSVD,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_RSVD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_RSVD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_RSVD,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_RSVD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_RSVD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_RSVD,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_RSVD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_LMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_LMIT,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_LMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_LMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_LMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_LMIT,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_LMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_LMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_LMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_LMIT,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_LMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_NCKO_LMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_RSVD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_RSVD,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_RSVD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_RSVD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_RSVD,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_RSVD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_RSVD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_RSVD,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_RSVD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_LMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_LMIT,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_LMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_LMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_LMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_LMIT,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_LMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_LMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_LMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_LMIT,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_LMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_CHKO_LMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_RSVD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_RSVD,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_RSVD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_RSVD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_RSVD,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_RSVD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_RSVD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_RSVD,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_RSVD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_LMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_LMIT,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_LMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_LMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_LMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_LMIT,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_LMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_LMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_LMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_LMIT,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_LMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_VC_LCL_LMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_32_33,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_32_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_32_33,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_32_33,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_32_33_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_MAX(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_MAX,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_MAX,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_MAX(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_MAX,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_CRD_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_40_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_40_41,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_40_41_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_40_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_40_41,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_40_41_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_40_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_40_41,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_40_41_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_RSVD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_RSVD,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_RSVD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_RSVD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_RSVD,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_RSVD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_RSVD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_RSVD,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_RSVD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_RSVD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_44_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_44_45,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_44_45_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_44_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_44_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_44_45,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_44_45_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_44_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_44_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_44_45,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_44_45_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_44_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_NCKO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_NCKO,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_NCKO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_NCKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_NCKO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_NCKO,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_NCKO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_NCKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_NCKO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_NCKO,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_NCKO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_NCKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_48_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_48_49,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_48_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_48_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_48_49,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_48_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_48_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_48_49,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_48_49_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_CHKO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_CHKO,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_CHKO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_CHKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_CHKO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_CHKO,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_CHKO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_CHKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_CHKO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_CHKO,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_CHKO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_CHKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_52_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_52_53,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_52_53_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_52_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_52_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_52_53,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_52_53_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_52_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_52_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_52_53,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_52_53_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_52_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_VC_LCL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_VC_LCL,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_VC_LCL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_VC_LCL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_VC_LCL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_VC_LCL,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_VC_LCL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_VC_LCL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_VC_LCL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_VC_LCL,
           INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_VC_LCL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_CFG_NXC_LD_ARB_PRIO_VC_LCL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_56_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_56_63,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_56_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_56_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_56_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_56_63,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_56_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_56_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_56_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a8b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_56_63,
           INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_56_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_LOAD_CONFIG_RESERVED_56_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_WATCH0_DATA2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010aa6;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_WATCH0_DATA2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010aa6;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_WATCH0_DATA2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_WATCH0_DATA2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010aa6));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_WATCH0_DATA2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_DBG_PMC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a34;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_DBG_PMC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a34;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_DBG_PMC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_DBG_PMC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_DBG_PMC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ARX_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_ARX_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ARX_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ARX_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_ARX_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ARX_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ARX_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_ARX_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ARX_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_ARX_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_ARX_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ARX_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_ARX_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_ARX_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ARX_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_ARX_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_ARX_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ARX_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ARX_NXC_REGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CRESP_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CRESP_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CRESP_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CRESP_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CRESP_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CRESP_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CRESP_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CRESP_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CRESP_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CRESP_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CRESP_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CRESP_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_RCMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CRESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CRESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CRESP_CAM_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST_UTIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_LDST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_DONE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_MMIO_PCMD_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_ARB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_ARB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_ARB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_ARB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_ARB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CMD_ARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CMD_ARB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CMD_ARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CMD_ARB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CMD_ARB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CMD_ARB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CMD_ARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_RCMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_MMIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_PROC_NXC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_PEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_NRQ_ARB_DETAIL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_BLCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_BLCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_BLCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_BLCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_CMD_BLCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_BLCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_CMD_BLCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_CMD_BLCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_BLCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_CMD_BLCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_CMD_BLCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_BLCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_CMD_BLCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_CMD_BLCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_BLCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_CMD_BLCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_CMD_BLCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_CMD_BLCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_CMD_LAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ATX_ARB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_ATX_ARB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ATX_ARB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_EN_ATX_ARB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_EN_ATX_ARB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_PMC_EN_ATX_ARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_PMC_EN_ATX_ARB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_PMC_EN_ATX_ARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_EN_ATX_ARB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_EN_ATX_ARB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_PMC_EN_ATX_ARB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_PMC_EN_ATX_ARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_EN_ATX_ARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_RESERVED_24_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_RESERVED_24_31,
           INT_PC_REGS_DBG_PMC_RESERVED_24_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_RESERVED_24_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_RESERVED_24_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_RESERVED_24_31,
           INT_PC_REGS_DBG_PMC_RESERVED_24_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_RESERVED_24_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_RESERVED_24_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a34));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_RESERVED_24_31,
           INT_PC_REGS_DBG_PMC_RESERVED_24_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_RESERVED_24_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_NVP_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a0c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_NVP_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a0c;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_NVP_BLOCK_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_NVP_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010a0c));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_NVP_BLOCK_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NVP_BLOCK_MODE_INT_PC_NVP_BLOCK_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a0c));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NVP_BLOCK_MODE_INT_PC_NVP_BLOCK_MODE,
           INT_PC_REGS_NVP_BLOCK_MODE_INT_PC_NVP_BLOCK_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NVP_BLOCK_MODE_INT_PC_NVP_BLOCK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NVP_BLOCK_MODE_INT_PC_NVP_BLOCK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a0c));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NVP_BLOCK_MODE_INT_PC_NVP_BLOCK_MODE,
           INT_PC_REGS_NVP_BLOCK_MODE_INT_PC_NVP_BLOCK_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NVP_BLOCK_MODE_INT_PC_NVP_BLOCK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_NVP_BLOCK_MODE_INT_PC_NVP_BLOCK_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a0c));
#endif
    return i_data.extractToRight<INT_PC_REGS_NVP_BLOCK_MODE_INT_PC_NVP_BLOCK_MODE,
           INT_PC_REGS_NVP_BLOCK_MODE_INT_PC_NVP_BLOCK_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NVP_BLOCK_MODE_INT_PC_NVP_BLOCK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_TCTXT_DEBUG_DATA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010b2d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_TCTXT_DEBUG_DATA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010b2d;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_TCTXT_DEBUG_DATA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_TCTXT_DEBUG_DATA(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010b2d));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_TCTXT_DEBUG_DATA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_TCTXT_LSI_STEOI_LD(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010b21;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_TCTXT_LSI_STEOI_LD(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010b21;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_TCTXT_LSI_STEOI_LD, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_TCTXT_LSI_STEOI_LD(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010b21));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_TCTXT_LSI_STEOI_LD, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_EASC_DBG_CACHE_EN(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010975;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_EASC_DBG_CACHE_EN(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010975;
#endif
    return fapi2::getScom(i_target, INT_VC_EASC_DBG_CACHE_EN, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_EASC_DBG_CACHE_EN(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010975));
#endif
    return fapi2::putScom(i_target, INT_VC_EASC_DBG_CACHE_EN, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_CACHE_EN_INT_VC_EASC_DBG_CACHE_EN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010975));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_CACHE_EN_INT_VC_EASC_DBG_CACHE_EN_ENABLE,
           INT_VC_EASC_DBG_CACHE_EN_INT_VC_EASC_DBG_CACHE_EN_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_CACHE_EN_INT_VC_EASC_DBG_CACHE_EN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_DBG_CACHE_EN_INT_VC_EASC_DBG_CACHE_EN_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010975));
#endif
    return o_data.insertFromRight<INT_VC_EASC_DBG_CACHE_EN_INT_VC_EASC_DBG_CACHE_EN_ENABLE,
           INT_VC_EASC_DBG_CACHE_EN_INT_VC_EASC_DBG_CACHE_EN_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_CACHE_EN_INT_VC_EASC_DBG_CACHE_EN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_DBG_CACHE_EN_INT_VC_EASC_DBG_CACHE_EN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010975));
#endif
    return i_data.extractToRight<INT_VC_EASC_DBG_CACHE_EN_INT_VC_EASC_DBG_CACHE_EN_ENABLE,
           INT_VC_EASC_DBG_CACHE_EN_INT_VC_EASC_DBG_CACHE_EN_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_DBG_CACHE_EN_INT_VC_EASC_DBG_CACHE_EN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_EASC_HASH_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201096b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_EASC_HASH_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201096b;
#endif
    return fapi2::getScom(i_target, INT_VC_EASC_HASH_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_EASC_HASH_3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return fapi2::putScom(i_target, INT_VC_EASC_HASH_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_3_NXC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_3_NXC,
           INT_VC_EASC_HASH_3_NXC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_NXC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_3_NXC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_3_NXC,
           INT_VC_EASC_HASH_3_NXC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_NXC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_HASH_3_NXC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return i_data.extractToRight<INT_VC_EASC_HASH_3_NXC,
           INT_VC_EASC_HASH_3_NXC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_NXC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_3_INT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_3_INT,
           INT_VC_EASC_HASH_3_INT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_3_INT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_3_INT,
           INT_VC_EASC_HASH_3_INT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_HASH_3_INT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return i_data.extractToRight<INT_VC_EASC_HASH_3_INT,
           INT_VC_EASC_HASH_3_INT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_3_OS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_3_OS,
           INT_VC_EASC_HASH_3_OS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_OS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_3_OS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_3_OS,
           INT_VC_EASC_HASH_3_OS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_OS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_HASH_3_OS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return i_data.extractToRight<INT_VC_EASC_HASH_3_OS,
           INT_VC_EASC_HASH_3_OS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_OS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_3_POOL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_3_POOL,
           INT_VC_EASC_HASH_3_POOL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_3_POOL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_3_POOL,
           INT_VC_EASC_HASH_3_POOL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_HASH_3_POOL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return i_data.extractToRight<INT_VC_EASC_HASH_3_POOL,
           INT_VC_EASC_HASH_3_POOL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_3_HARD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_3_HARD,
           INT_VC_EASC_HASH_3_HARD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_HARD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_3_HARD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_3_HARD,
           INT_VC_EASC_HASH_3_HARD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_HARD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_HASH_3_HARD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return i_data.extractToRight<INT_VC_EASC_HASH_3_HARD,
           INT_VC_EASC_HASH_3_HARD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_HARD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_3_LOCAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_3_LOCAL,
           INT_VC_EASC_HASH_3_LOCAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_LOCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_HASH_3_LOCAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return o_data.insertFromRight<INT_VC_EASC_HASH_3_LOCAL,
           INT_VC_EASC_HASH_3_LOCAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_LOCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_HASH_3_LOCAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201096b));
#endif
    return i_data.extractToRight<INT_VC_EASC_HASH_3_LOCAL,
           INT_VC_EASC_HASH_3_LOCAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_HASH_3_LOCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_EASC_PERF_EVENT_SEL_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010979;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_EASC_PERF_EVENT_SEL_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010979;
#endif
    return fapi2::getScom(i_target, INT_VC_EASC_PERF_EVENT_SEL_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_EASC_PERF_EVENT_SEL_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010979));
#endif
    return fapi2::putScom(i_target, INT_VC_EASC_PERF_EVENT_SEL_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_2_PRF_CACHE_HIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010979));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_2_PRF_CACHE_HIT,
           INT_VC_EASC_PERF_EVENT_SEL_2_PRF_CACHE_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_2_PRF_CACHE_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_2_PRF_CACHE_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010979));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_2_PRF_CACHE_HIT,
           INT_VC_EASC_PERF_EVENT_SEL_2_PRF_CACHE_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_2_PRF_CACHE_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_PERF_EVENT_SEL_2_PRF_CACHE_HIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010979));
#endif
    return i_data.extractToRight<INT_VC_EASC_PERF_EVENT_SEL_2_PRF_CACHE_HIT,
           INT_VC_EASC_PERF_EVENT_SEL_2_PRF_CACHE_HIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_2_PRF_CACHE_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_2_DEM_CACHE_HIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010979));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_2_DEM_CACHE_HIT,
           INT_VC_EASC_PERF_EVENT_SEL_2_DEM_CACHE_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_2_DEM_CACHE_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_2_DEM_CACHE_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010979));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_2_DEM_CACHE_HIT,
           INT_VC_EASC_PERF_EVENT_SEL_2_DEM_CACHE_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_2_DEM_CACHE_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_PERF_EVENT_SEL_2_DEM_CACHE_HIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010979));
#endif
    return i_data.extractToRight<INT_VC_EASC_PERF_EVENT_SEL_2_DEM_CACHE_HIT,
           INT_VC_EASC_PERF_EVENT_SEL_2_DEM_CACHE_HIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_2_DEM_CACHE_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_LRU(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010979));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_LRU,
           INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_LRU_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_LRU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_LRU(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010979));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_LRU,
           INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_LRU_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_LRU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_LRU(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010979));
#endif
    return i_data.extractToRight<INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_LRU,
           INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_LRU_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_LRU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_1ST_EXCLUSIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010979));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_1ST_EXCLUSIVE,
           INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_1ST_EXCLUSIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_1ST_EXCLUSIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_1ST_EXCLUSIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010979));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_1ST_EXCLUSIVE,
           INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_1ST_EXCLUSIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_1ST_EXCLUSIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_1ST_EXCLUSIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010979));
#endif
    return i_data.extractToRight<INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_1ST_EXCLUSIVE,
           INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_1ST_EXCLUSIVE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_2_VICTIM_IS_1ST_EXCLUSIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_2_RETRY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010979));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_2_RETRY,
           INT_VC_EASC_PERF_EVENT_SEL_2_RETRY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_2_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_PERF_EVENT_SEL_2_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010979));
#endif
    return o_data.insertFromRight<INT_VC_EASC_PERF_EVENT_SEL_2_RETRY,
           INT_VC_EASC_PERF_EVENT_SEL_2_RETRY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_2_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_PERF_EVENT_SEL_2_RETRY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010979));
#endif
    return i_data.extractToRight<INT_VC_EASC_PERF_EVENT_SEL_2_RETRY,
           INT_VC_EASC_PERF_EVENT_SEL_2_RETRY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_PERF_EVENT_SEL_2_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_PERF_EVENT_SEL_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010999;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_PERF_EVENT_SEL_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010999;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_PERF_EVENT_SEL_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_PERF_EVENT_SEL_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_PERF_EVENT_SEL_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INBOUND_LOADS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INBOUND_LOADS,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INBOUND_LOADS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INBOUND_LOADS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INBOUND_LOADS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INBOUND_LOADS,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INBOUND_LOADS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INBOUND_LOADS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INBOUND_LOADS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INBOUND_LOADS,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INBOUND_LOADS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INBOUND_LOADS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOCAL_ESC_OR_FW_FWD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOCAL_ESC_OR_FW_FWD,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOCAL_ESC_OR_FW_FWD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOCAL_ESC_OR_FW_FWD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOCAL_ESC_OR_FW_FWD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOCAL_ESC_OR_FW_FWD,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOCAL_ESC_OR_FW_FWD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOCAL_ESC_OR_FW_FWD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOCAL_ESC_OR_FW_FWD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOCAL_ESC_OR_FW_FWD,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOCAL_ESC_OR_FW_FWD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOCAL_ESC_OR_FW_FWD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_EQA_CMD_CACHE_HIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_EQA_CMD_CACHE_HIT,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_EQA_CMD_CACHE_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_EQA_CMD_CACHE_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_EQA_CMD_CACHE_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_EQA_CMD_CACHE_HIT,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_EQA_CMD_CACHE_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_EQA_CMD_CACHE_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_EQA_CMD_CACHE_HIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_EQA_CMD_CACHE_HIT,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_EQA_CMD_CACHE_HIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_EQA_CMD_CACHE_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INB_LOAD_HIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INB_LOAD_HIT,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INB_LOAD_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INB_LOAD_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INB_LOAD_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INB_LOAD_HIT,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INB_LOAD_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INB_LOAD_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INB_LOAD_HIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INB_LOAD_HIT,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INB_LOAD_HIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_INB_LOAD_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOC_ESC_HIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOC_ESC_HIT,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOC_ESC_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOC_ESC_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOC_ESC_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOC_ESC_HIT,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOC_ESC_HIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOC_ESC_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOC_ESC_HIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOC_ESC_HIT,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOC_ESC_HIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_LOC_ESC_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_LRU(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_LRU,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_LRU_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_LRU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_LRU(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_LRU,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_LRU_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_LRU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_LRU(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_LRU,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_LRU_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_LRU chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_1ST_USABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_1ST_USABLE,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_1ST_USABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_1ST_USABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_1ST_USABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_1ST_USABLE,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_1ST_USABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_1ST_USABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_1ST_USABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_1ST_USABLE,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_1ST_USABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_VICTIM_IS_1ST_USABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_RETRY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_RETRY,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_RETRY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_RETRY,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_RETRY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_RETRY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_RETRY,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_RETRY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_TOO_MANY_ENTRIES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_TOO_MANY_ENTRIES,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_TOO_MANY_ENTRIES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_TOO_MANY_ENTRIES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_TOO_MANY_ENTRIES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_TOO_MANY_ENTRIES,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_TOO_MANY_ENTRIES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_TOO_MANY_ENTRIES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_TOO_MANY_ENTRIES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_TOO_MANY_ENTRIES,
           INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_TOO_MANY_ENTRIES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_CNT_TOO_MANY_ENTRIES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_RESERVED_36_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_RESERVED_36_63,
           INT_VC_ENDC_PERF_EVENT_SEL_2_RESERVED_36_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_RESERVED_36_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_2_RESERVED_36_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_2_RESERVED_36_63,
           INT_VC_ENDC_PERF_EVENT_SEL_2_RESERVED_36_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_RESERVED_36_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_2_RESERVED_36_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010999));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_2_RESERVED_36_63,
           INT_VC_ENDC_PERF_EVENT_SEL_2_RESERVED_36_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_2_RESERVED_36_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_WATCH3_DATA0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20109bc;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_WATCH3_DATA0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20109bc;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_WATCH3_DATA0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_WATCH3_DATA0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20109bc));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_WATCH3_DATA0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ESBC_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010940;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ESBC_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010940;
#endif
    return fapi2::getScom(i_target, INT_VC_ESBC_FLUSH_CTRL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ESBC_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return fapi2::putScom(i_target, INT_VC_ESBC_FLUSH_CTRL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_FLUSH_CTRL_POLL_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_POLL_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_FLUSH_CTRL_POLL_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return o_data.setBit<INT_VC_ESBC_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ESBC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return o_data.clearBit<INT_VC_ESBC_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return i_data.extractToRight<INT_VC_ESBC_FLUSH_CTRL_POLL_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_ESBC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return i_data.getBit<INT_VC_ESBC_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_FLUSH_CTRL_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_RESERVED_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_FLUSH_CTRL_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return o_data.setBit<INT_VC_ESBC_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ESBC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return o_data.clearBit<INT_VC_ESBC_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return i_data.extractToRight<INT_VC_ESBC_FLUSH_CTRL_RESERVED_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_ESBC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return i_data.getBit<INT_VC_ESBC_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return o_data.setBit<INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return o_data.clearBit<INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return i_data.extractToRight<INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return i_data.getBit<INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7,
           INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7,
           INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010940));
#endif
    return i_data.extractToRight<INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7,
           INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_QUEUES_CFG_REM_5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201091c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_QUEUES_CFG_REM_5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201091c;
#endif
    return fapi2::getScom(i_target, INT_VC_QUEUES_CFG_REM_5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_QUEUES_CFG_REM_5(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return fapi2::putScom(i_target, INT_VC_QUEUES_CFG_REM_5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_PREFETCH_DISTANCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_PREFETCH_DISTANCE,
           INT_VC_QUEUES_CFG_REM_5_IRQ_PREFETCH_DISTANCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_PREFETCH_DISTANCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_PREFETCH_DISTANCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_PREFETCH_DISTANCE,
           INT_VC_QUEUES_CFG_REM_5_IRQ_PREFETCH_DISTANCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_PREFETCH_DISTANCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_IRQ_PREFETCH_DISTANCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_IRQ_PREFETCH_DISTANCE,
           INT_VC_QUEUES_CFG_REM_5_IRQ_PREFETCH_DISTANCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_PREFETCH_DISTANCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_RESERVED_8_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_8_10,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_8_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_8_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_RESERVED_8_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_8_10,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_8_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_8_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_RESERVED_8_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_8_10,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_8_10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_8_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_CQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_CQ,
           INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_CQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_CQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_CQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_CQ,
           INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_CQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_CQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_CQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_CQ,
           INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_CQ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_CQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_RESERVED_16_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_16_18,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_16_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_16_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_RESERVED_16_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_16_18,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_16_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_16_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_RESERVED_16_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_16_18,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_16_18_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_16_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_PC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_PC,
           INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_PC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_PC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_PC,
           INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_PC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_PC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_PC,
           INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_PC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_CRD_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_NB_OUTSTANDING_DEM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_NB_OUTSTANDING_DEM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_MAX_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_MIN_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_MIN_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_5_IRQ_MIN_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_MIN_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_MIN_NB_OUTSTANDING_DEM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_MIN_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_5_IRQ_MIN_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_MIN_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_IRQ_MIN_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_IRQ_MIN_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_5_IRQ_MIN_NB_OUTSTANDING_DEM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_MIN_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_32_33,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_RESERVED_32_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_32_33,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_32_33,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_32_33_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_5_IRQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_5_IRQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_5_IRQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_IRQ_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_IRQ_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_5_IRQ_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_5_IRQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_RESERVED_36_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_36_37,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_36_37_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_36_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_RESERVED_36_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_36_37,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_36_37_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_36_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_RESERVED_36_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_36_37,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_36_37_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_36_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_RESERVED_40_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_40_41,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_40_41_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_RESERVED_40_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_40_41,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_40_41_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_RESERVED_40_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_40_41,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_40_41_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_MEM_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_ERQ_MEM_SIZE,
           INT_VC_QUEUES_CFG_REM_5_ERQ_MEM_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_MEM_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_ERQ_MEM_SIZE,
           INT_VC_QUEUES_CFG_REM_5_ERQ_MEM_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_ERQ_MEM_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_ERQ_MEM_SIZE,
           INT_VC_QUEUES_CFG_REM_5_ERQ_MEM_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_RESERVED_48_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_48_49,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_48_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_RESERVED_48_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_48_49,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_48_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_RESERVED_48_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_RESERVED_48_49,
           INT_VC_QUEUES_CFG_REM_5_RESERVED_48_49_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_ERQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_ERQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_5_ERQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_5_ERQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_5_ERQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_ERQ_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_ERQ_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_5_ERQ_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_5_ERQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201091c));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_5_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_QUEUES_PERF_EVENT_SEL_6(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201092c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_QUEUES_PERF_EVENT_SEL_6(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201092c;
#endif
    return fapi2::getScom(i_target, INT_VC_QUEUES_PERF_EVENT_SEL_6, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_QUEUES_PERF_EVENT_SEL_6(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return fapi2::putScom(i_target, INT_VC_QUEUES_PERF_EVENT_SEL_6, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_6_FROM_AIB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_FROM_AIB,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_FROM_AIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_FROM_AIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_6_FROM_AIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_FROM_AIB,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_FROM_AIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_FROM_AIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_6_FROM_AIB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_FROM_AIB,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_FROM_AIB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_FROM_AIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_6_IRQ_TO_IQA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_IRQ_TO_IQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_IRQ_TO_IQA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_IRQ_TO_IQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_6_IRQ_TO_IQA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_IRQ_TO_IQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_IRQ_TO_IQA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_IRQ_TO_IQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_6_IRQ_TO_IQA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_IRQ_TO_IQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_IRQ_TO_IQA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_IRQ_TO_IQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_DPS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_DPS,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_DPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_DPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_DPS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_DPS,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_DPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_DPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_DPS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_DPS,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_DPS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_DPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_IQS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_IQS,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_IQS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_IQS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_IQS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_IQS,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_IQS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_IQS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_IQS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_IQS,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_IQS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_IQA_TO_IQS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_6_IQS_TO_EQA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_IQS_TO_EQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_IQS_TO_EQA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_IQS_TO_EQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_6_IQS_TO_EQA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_IQS_TO_EQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_IQS_TO_EQA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_IQS_TO_EQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_6_IQS_TO_EQA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_IQS_TO_EQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_IQS_TO_EQA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_IQS_TO_EQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ERQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ERQ,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ERQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ERQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ERQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ERQ,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ERQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ERQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ERQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ERQ,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ERQ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ERQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ATX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ATX,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ATX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ATX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ATX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ATX,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ATX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ATX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ATX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ATX,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ATX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ATX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ENDC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ENDC,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ENDC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ENDC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ENDC,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ENDC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ENDC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201092c));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ENDC,
           INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ENDC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_6_EQA_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_BANK0_REC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010810;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_BANK0_REC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010810;
#endif
    return fapi2::getScom(i_target, MCD_BANK0_REC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_BANK0_REC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return fapi2::putScom(i_target, MCD_BANK0_REC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.setBit<MCD_BANK0_REC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_REC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.clearBit<MCD_BANK0_REC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_REC_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return i_data.getBit<MCD_BANK0_REC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.setBit<MCD_BANK0_REC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_REC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.clearBit<MCD_BANK0_REC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_REC_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return i_data.getBit<MCD_BANK0_REC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_CONTINUOUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_CONTINUOUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_CONTINUOUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_CONTINUOUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_CONTINUOUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_CONTINUOUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_CONTINUOUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.setBit<MCD_BANK0_REC_CONTINUOUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_CONTINUOUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_REC_CONTINUOUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.clearBit<MCD_BANK0_REC_CONTINUOUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_CONTINUOUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_CONTINUOUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_CONTINUOUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_CONTINUOUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_REC_CONTINUOUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return i_data.getBit<MCD_BANK0_REC_CONTINUOUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_CONTINUOUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.setBit<MCD_BANK0_REC_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_REC_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.clearBit<MCD_BANK0_REC_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_REC_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return i_data.getBit<MCD_BANK0_REC_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_PACE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_PACE,
           MCD_BANK0_REC_PACE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_PACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_PACE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_PACE,
           MCD_BANK0_REC_PACE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_PACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_PACE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_PACE,
           MCD_BANK0_REC_PACE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_PACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_ADDR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_ADDR_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_ADDR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_ADDR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.setBit<MCD_BANK0_REC_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_REC_ADDR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.clearBit<MCD_BANK0_REC_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_ADDR_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_REC_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return i_data.getBit<MCD_BANK0_REC_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_ADDR,
           MCD_BANK0_REC_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_ADDR,
           MCD_BANK0_REC_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_ADDR,
           MCD_BANK0_REC_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_RTY_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_RTY_COUNT,
           MCD_BANK0_REC_RTY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_RTY_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_RTY_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_RTY_COUNT,
           MCD_BANK0_REC_RTY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_RTY_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_RTY_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_RTY_COUNT,
           MCD_BANK0_REC_RTY_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_RTY_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_VG_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_VG_COUNT,
           MCD_BANK0_REC_VG_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_VG_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_VG_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_VG_COUNT,
           MCD_BANK0_REC_VG_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_VG_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_VG_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010810));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_VG_COUNT,
           MCD_BANK0_REC_VG_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_REC_VG_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010806;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010806;
#endif
    return fapi2::getScom(i_target, MCD_FIR_ACTION0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3010806));
#endif
    return fapi2::putScom(i_target, MCD_FIR_ACTION0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_ACTION0_REG_FIR_ACTION0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010806));
#endif
    return o_data.insertFromRight<MCD_FIR_ACTION0_REG_FIR_ACTION0,
           MCD_FIR_ACTION0_REG_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_ACTION0_REG_FIR_ACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_ACTION0_REG_FIR_ACTION0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010806));
#endif
    return o_data.insertFromRight<MCD_FIR_ACTION0_REG_FIR_ACTION0,
           MCD_FIR_ACTION0_REG_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_ACTION0_REG_FIR_ACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_ACTION0_REG_FIR_ACTION0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010806));
#endif
    return i_data.extractToRight<MCD_FIR_ACTION0_REG_FIR_ACTION0,
           MCD_FIR_ACTION0_REG_FIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_ACTION0_REG_FIR_ACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010807;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010807;
#endif
    return fapi2::getScom(i_target, MCD_FIR_ACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3010807));
#endif
    return fapi2::putScom(i_target, MCD_FIR_ACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_ACTION1_REG_FIR_ACTION1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010807));
#endif
    return o_data.insertFromRight<MCD_FIR_ACTION1_REG_FIR_ACTION1,
           MCD_FIR_ACTION1_REG_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_ACTION1_REG_FIR_ACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_ACTION1_REG_FIR_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010807));
#endif
    return o_data.insertFromRight<MCD_FIR_ACTION1_REG_FIR_ACTION1,
           MCD_FIR_ACTION1_REG_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_ACTION1_REG_FIR_ACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_ACTION1_REG_FIR_ACTION1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010807));
#endif
    return i_data.extractToRight<MCD_FIR_ACTION1_REG_FIR_ACTION1,
           MCD_FIR_ACTION1_REG_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_FIR_ACTION1_REG_FIR_ACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c2c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c2c;
#endif
    return fapi2::getScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c2c));
#endif
    return fapi2::putScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c2c));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c2c));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c2c));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c2d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c2d;
#endif
    return fapi2::getScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c2d));
#endif
    return fapi2::putScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c2d));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c2d));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c2d));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c2e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c2e;
#endif
    return fapi2::getScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c2e));
#endif
    return fapi2::putScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c2e));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c2e));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c2e));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c2f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c2f;
#endif
    return fapi2::getScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c2f));
#endif
    return fapi2::putScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c2f));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c2f));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c2f));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM1_MM_CFG_NMMU_XLAT_CTL_REG2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010c4c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM1_MM_CFG_NMMU_XLAT_CTL_REG2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010c4c;
#endif
    return fapi2::getScom(i_target, MM1_MM_CFG_NMMU_XLAT_CTL_REG2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM1_MM_CFG_NMMU_XLAT_CTL_REG2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3010c4c));
#endif
    return fapi2::putScom(i_target, MM1_MM_CFG_NMMU_XLAT_CTL_REG2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c4c));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR,
           MM1_MM_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c4c));
#endif
    return o_data.insertFromRight<MM1_MM_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR,
           MM1_MM_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c4c));
#endif
    return i_data.extractToRight<MM1_MM_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR,
           MM1_MM_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_CFG_NMMU_XLAT_CTL_REG2_MM_CFG_XLAT_CTL_URMOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010c1d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010c1d;
#endif
    return fapi2::getScom(i_target, MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return fapi2::putScom(i_target, MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL,
           MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL,
           MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return i_data.extractToRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL,
           MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL,
           MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL,
           MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return i_data.extractToRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL,
           MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL,
           MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL,
           MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return i_data.extractToRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL,
           MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL,
           MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL,
           MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return i_data.extractToRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL,
           MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return o_data.setBit<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return o_data.clearBit<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return i_data.extractToRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c1d));
#endif
    return i_data.getBit<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010c10;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010c10;
#endif
    return fapi2::getScom(i_target, MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3010c10));
#endif
    return fapi2::putScom(i_target, MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG_NXCQ_TRACE_CNTL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c10));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG_NXCQ_TRACE_CNTL,
           MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG_NXCQ_TRACE_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG_NXCQ_TRACE_CNTL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG_NXCQ_TRACE_CNTL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c10));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG_NXCQ_TRACE_CNTL,
           MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG_NXCQ_TRACE_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG_NXCQ_TRACE_CNTL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG_NXCQ_TRACE_CNTL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c10));
#endif
    return i_data.extractToRight<MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG_NXCQ_TRACE_CNTL,
           MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG_NXCQ_TRACE_CNTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_DEBUG_REG_NXCQ_TRACE_CNTL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010c25;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010c25;
#endif
    return fapi2::getScom(i_target, MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3010c25));
#endif
    return fapi2::putScom(i_target, MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c25));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87,
           MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c25));
#endif
    return o_data.insertFromRight<MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87,
           MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c25));
#endif
    return i_data.extractToRight<MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87,
           MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_CH4_ADDR_0_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011141;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_CH4_ADDR_0_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011141;
#endif
    return fapi2::getScom(i_target, NX_CH4_ADDR_0_HASH_FUNCTION_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_CH4_ADDR_0_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011141));
#endif
    return fapi2::putScom(i_target, NX_CH4_ADDR_0_HASH_FUNCTION_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_CH4_ADDR_0_HASH_FUNCTION_REG_ADDRESS_0_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011141));
#endif
    return o_data.insertFromRight<NX_CH4_ADDR_0_HASH_FUNCTION_REG_ADDRESS_0_HASH_FUNCTION,
           NX_CH4_ADDR_0_HASH_FUNCTION_REG_ADDRESS_0_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_0_HASH_FUNCTION_REG_ADDRESS_0_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_ADDR_0_HASH_FUNCTION_REG_ADDRESS_0_HASH_FUNCTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011141));
#endif
    return o_data.insertFromRight<NX_CH4_ADDR_0_HASH_FUNCTION_REG_ADDRESS_0_HASH_FUNCTION,
           NX_CH4_ADDR_0_HASH_FUNCTION_REG_ADDRESS_0_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_0_HASH_FUNCTION_REG_ADDRESS_0_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_ADDR_0_HASH_FUNCTION_REG_ADDRESS_0_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011141));
#endif
    return i_data.extractToRight<NX_CH4_ADDR_0_HASH_FUNCTION_REG_ADDRESS_0_HASH_FUNCTION,
           NX_CH4_ADDR_0_HASH_FUNCTION_REG_ADDRESS_0_HASH_FUNCTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_0_HASH_FUNCTION_REG_ADDRESS_0_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_CH4_DATATAG_4_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011150;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_CH4_DATATAG_4_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011150;
#endif
    return fapi2::getScom(i_target, NX_CH4_DATATAG_4_HASH_FUNCTION_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_CH4_DATATAG_4_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011150));
#endif
    return fapi2::putScom(i_target, NX_CH4_DATATAG_4_HASH_FUNCTION_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_CH4_DATATAG_4_HASH_FUNCTION_REG_DATATAG_4_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011150));
#endif
    return o_data.insertFromRight<NX_CH4_DATATAG_4_HASH_FUNCTION_REG_DATATAG_4_HASH_FUNCTION,
           NX_CH4_DATATAG_4_HASH_FUNCTION_REG_DATATAG_4_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_DATATAG_4_HASH_FUNCTION_REG_DATATAG_4_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_DATATAG_4_HASH_FUNCTION_REG_DATATAG_4_HASH_FUNCTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011150));
#endif
    return o_data.insertFromRight<NX_CH4_DATATAG_4_HASH_FUNCTION_REG_DATATAG_4_HASH_FUNCTION,
           NX_CH4_DATATAG_4_HASH_FUNCTION_REG_DATATAG_4_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_DATATAG_4_HASH_FUNCTION_REG_DATATAG_4_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_DATATAG_4_HASH_FUNCTION_REG_DATATAG_4_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011150));
#endif
    return i_data.extractToRight<NX_CH4_DATATAG_4_HASH_FUNCTION_REG_DATATAG_4_HASH_FUNCTION,
           NX_CH4_DATATAG_4_HASH_FUNCTION_REG_DATATAG_4_HASH_FUNCTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_DATATAG_4_HASH_FUNCTION_REG_DATATAG_4_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_DMA_SU_PERFMON_CONTROL_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011055;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_DMA_SU_PERFMON_CONTROL_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011055;
#endif
    return fapi2::getScom(i_target, NX_DMA_SU_PERFMON_CONTROL_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_DMA_SU_PERFMON_CONTROL_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return fapi2::putScom(i_target, NX_DMA_SU_PERFMON_CONTROL_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_GZIP_FC_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_GZIP_FC_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_GZIP_FC_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_GZIP_FC_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_GZIP_FC_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_GZIP_FC_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_GZIP_FC_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_GZIP_FC_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_1_GZIP_FC_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_1_GZIP_FC_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_GZIP_FC_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_GZIP_FC_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_842_FC_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_842_FC_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_842_FC_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_842_FC_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_842_FC_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_842_FC_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_842_FC_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_842_FC_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_1_842_FC_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_1_842_FC_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_842_FC_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_842_FC_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_DMA_MUX_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_DMA_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_DMA_MUX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_DMA_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_DMA_MUX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_DMA_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_DMA_MUX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_DMA_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_1_DMA_MUX_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_1_DMA_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_DMA_MUX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_DMA_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_EFT_MUX_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_EFT_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_EFT_MUX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_EFT_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_EFT_MUX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_EFT_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_EFT_MUX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_EFT_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_1_EFT_MUX_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_1_EFT_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_EFT_MUX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_EFT_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_GZIP_MUX_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_GZIP_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_GZIP_MUX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_GZIP_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_GZIP_MUX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_GZIP_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_GZIP_MUX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_GZIP_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_1_GZIP_MUX_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_1_GZIP_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_GZIP_MUX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_GZIP_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_ERAT_MUX_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_ERAT_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_ERAT_MUX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_ERAT_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_ERAT_MUX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_ERAT_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_ERAT_MUX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_ERAT_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_1_ERAT_MUX_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_1_ERAT_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_ERAT_MUX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_ERAT_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_UMAC_MUX_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_UMAC_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_UMAC_MUX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_UMAC_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_UMAC_MUX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_UMAC_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_UMAC_MUX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_UMAC_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_1_UMAC_MUX_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_1_UMAC_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_UMAC_MUX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_UMAC_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_PBI_MUX_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_PBI_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_PBI_MUX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_PBI_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_PBI_MUX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_PBI_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_PBI_MUX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_PBI_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_1_PBI_MUX_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_1_PBI_MUX_SELECT,
           NX_DMA_SU_PERFMON_CONTROL_1_PBI_MUX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_PBI_MUX_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.setBit<NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.clearBit<NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.getBit<NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_SHA_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.setBit<NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.clearBit<NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.getBit<NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_MD5_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.setBit<NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.clearBit<NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.getBit<NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_AES_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.setBit<NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.clearBit<NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.getBit<NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_AESSHA_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.setBit<NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.clearBit<NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.getBit<NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_GZIP_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.insertFromRight<NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.setBit<NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return o_data.clearBit<NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.extractToRight<NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011055));
#endif
    return i_data.getBit<NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SU_PERFMON_CONTROL_1_842_LATENCY_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_RCMD_RATE_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1001180c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_RCMD_RATE_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1001180c;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_RCMD_RATE_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_RCMD_RATE_CFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1001180c));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_RCMD_RATE_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001180c));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE,
           PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001180c));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE,
           PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001180c));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE,
           PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001180c));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE,
           PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001180c));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE,
           PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001180c));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE,
           PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE_ADDER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001180c));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE_ADDER,
           PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE_ADDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE_ADDER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001180c));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE_ADDER,
           PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE_ADDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE_ADDER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001180c));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE_ADDER,
           PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE_ADDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_RCMD_RATE_CFG_X_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001180c));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER,
           PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001180c));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER,
           PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001180c));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER,
           PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_EN_DOB_ECC_ERR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011818;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_EN_DOB_ECC_ERR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011818;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_EN_DOB_ECC_ERR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_EN_DOB_ECC_ERR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x11011818));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_EN_DOB_ECC_ERR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_MAILBOX_20_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011834;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_MAILBOX_20_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011834;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_MAILBOX_20_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_MAILBOX_20_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x11011834));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_MAILBOX_20_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_MAILBOX_21_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011835;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_MAILBOX_21_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011835;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_MAILBOX_21_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_MAILBOX_21_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x11011835));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_MAILBOX_21_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PSAVE23_MODE_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011816;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PSAVE23_MODE_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011816;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PSAVE23_MODE_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PSAVE23_MODE_CFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x11011816));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PSAVE23_MODE_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE23_MODE_CFG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x11011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE23_MODE_CFG_MODE,
           PB_PTLSCOM23_PSAVE23_MODE_CFG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE23_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE23_MODE_CFG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x11011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE23_MODE_CFG_MODE,
           PB_PTLSCOM23_PSAVE23_MODE_CFG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE23_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PSAVE23_MODE_CFG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x11011816));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PSAVE23_MODE_CFG_MODE,
           PB_PTLSCOM23_PSAVE23_MODE_CFG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE23_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE23_MODE_CFG_WIDTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x11011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE23_MODE_CFG_WIDTH,
           PB_PTLSCOM23_PSAVE23_MODE_CFG_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE23_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE23_MODE_CFG_WIDTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x11011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE23_MODE_CFG_WIDTH,
           PB_PTLSCOM23_PSAVE23_MODE_CFG_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE23_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PSAVE23_MODE_CFG_WIDTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x11011816));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PSAVE23_MODE_CFG_WIDTH,
           PB_PTLSCOM23_PSAVE23_MODE_CFG_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE23_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE23_MODE_CFG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x11011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE23_MODE_CFG_SPARE,
           PB_PTLSCOM23_PSAVE23_MODE_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE23_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE23_MODE_CFG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x11011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE23_MODE_CFG_SPARE,
           PB_PTLSCOM23_PSAVE23_MODE_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE23_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PSAVE23_MODE_CFG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x11011816));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PSAVE23_MODE_CFG_SPARE,
           PB_PTLSCOM23_PSAVE23_MODE_CFG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE23_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE23_MODE_CFG_MIN_RAND_UC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x11011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE23_MODE_CFG_MIN_RAND_UC,
           PB_PTLSCOM23_PSAVE23_MODE_CFG_MIN_RAND_UC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE23_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE23_MODE_CFG_MIN_RAND_UC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x11011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE23_MODE_CFG_MIN_RAND_UC,
           PB_PTLSCOM23_PSAVE23_MODE_CFG_MIN_RAND_UC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE23_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PSAVE23_MODE_CFG_MIN_RAND_UC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x11011816));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PSAVE23_MODE_CFG_MIN_RAND_UC,
           PB_PTLSCOM23_PSAVE23_MODE_CFG_MIN_RAND_UC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE23_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_FM0123_ERR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011827;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_FM0123_ERR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011827;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_FM0123_ERR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_FM0123_ERR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x12011827));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_FM0123_ERR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_MAILBOX_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1201182f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_MAILBOX_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1201182f;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_MAILBOX_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_MAILBOX_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1201182f));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_MAILBOX_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PMU2_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1201181d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PMU2_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1201181d;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PMU2_TLPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PMU2_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1201181d));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PMU2_TLPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_CNPM_PMU_PRESCALER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011820;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011820;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_CNPM_PMU_PRESCALER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_CNPM_PMU_PRESCALER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_CNPM_PMU_PRESCALER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011820));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3,
           PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_MAILBOX_00_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011830;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_MAILBOX_00_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011830;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_MAILBOX_00_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_MAILBOX_00_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x13011830));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_MAILBOX_00_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_MAILBOX_01_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011831;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_MAILBOX_01_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011831;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_MAILBOX_01_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_MAILBOX_01_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x13011831));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_MAILBOX_01_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_PMU1_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011822;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_PMU1_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011822;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_PMU1_CNPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_PMU1_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x13011822));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_PMU1_CNPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_PTL_FIR_MASK_REG_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011803;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011803;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_PTL_FIR_MASK_REG_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_PTL_FIR_MASK_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_PTL_FIR_MASK_REG_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_PTL_FIR_MASK_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x4;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_PTL_FIR_MASK_REG_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_PTL_FIR_MASK_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_PTL_FIR_MASK_REG_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_PTL_FIR_MASK_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x5;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_PTL_FIR_MASK_REG_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_PTL_FIR_MASK_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_PTL_FIR_MASK_REG_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x5, 0x4, 0x13011803));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011810;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011810;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.setBit<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.clearBit<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return i_data.getBit<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.setBit<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.clearBit<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return i_data.getBit<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.setBit<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.clearBit<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return i_data.getBit<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011810));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2,
           PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_HCA_FIR_ACTION0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3012406;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_HCA_FIR_ACTION0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3012406;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_HCA_FIR_ACTION0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_HCA_FIR_ACTION0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3012406));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_HCA_FIR_ACTION0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_FIR_ACTION0_FIR_ACTION0_BITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3012406));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_FIR_ACTION0_FIR_ACTION0_BITS,
           PB_BRIDGE_HCA_FIR_ACTION0_FIR_ACTION0_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_FIR_ACTION0_FIR_ACTION0_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_FIR_ACTION0_FIR_ACTION0_BITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3012406));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_FIR_ACTION0_FIR_ACTION0_BITS,
           PB_BRIDGE_HCA_FIR_ACTION0_FIR_ACTION0_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_FIR_ACTION0_FIR_ACTION0_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_FIR_ACTION0_FIR_ACTION0_BITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3012406));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_FIR_ACTION0_FIR_ACTION0_BITS,
           PB_BRIDGE_HCA_FIR_ACTION0_FIR_ACTION0_BITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_FIR_ACTION0_FIR_ACTION0_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_HCA_DROP_COUNT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3012415;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_HCA_DROP_COUNT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3012415;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_HCA_DROP_COUNT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_HCA_DROP_COUNT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3012415));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_HCA_DROP_COUNT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_DROP_COUNT_REG_RCMD_DROP_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3012415));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_DROP_COUNT_REG_RCMD_DROP_COUNT,
           PB_BRIDGE_HCA_DROP_COUNT_REG_RCMD_DROP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DROP_COUNT_REG_RCMD_DROP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_DROP_COUNT_REG_RCMD_DROP_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3012415));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_DROP_COUNT_REG_RCMD_DROP_COUNT,
           PB_BRIDGE_HCA_DROP_COUNT_REG_RCMD_DROP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DROP_COUNT_REG_RCMD_DROP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_DROP_COUNT_REG_RCMD_DROP_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3012415));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_DROP_COUNT_REG_RCMD_DROP_COUNT,
           PB_BRIDGE_HCA_DROP_COUNT_REG_RCMD_DROP_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DROP_COUNT_REG_RCMD_DROP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_DROP_COUNT_REG_UPDATE_DROP_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3012415));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_DROP_COUNT_REG_UPDATE_DROP_COUNT,
           PB_BRIDGE_HCA_DROP_COUNT_REG_UPDATE_DROP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DROP_COUNT_REG_UPDATE_DROP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_DROP_COUNT_REG_UPDATE_DROP_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3012415));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_DROP_COUNT_REG_UPDATE_DROP_COUNT,
           PB_BRIDGE_HCA_DROP_COUNT_REG_UPDATE_DROP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DROP_COUNT_REG_UPDATE_DROP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_DROP_COUNT_REG_UPDATE_DROP_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3012415));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_DROP_COUNT_REG_UPDATE_DROP_COUNT,
           PB_BRIDGE_HCA_DROP_COUNT_REG_UPDATE_DROP_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DROP_COUNT_REG_UPDATE_DROP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_2_PFIRWOF_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x80108c8;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_2_PFIRWOF_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x80108c8;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_2_PFIRWOF_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_2_PFIRWOF_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x80108c8));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_2_PFIRWOF_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}



}
}

#endif
