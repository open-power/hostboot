/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00007.H $          */
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

#ifndef __MCC_REG00007_H_
#define __MCC_REG00007_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ATCL_CL_CLSCOM_MCBUSYQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCBUSYQ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ATCL_CL_CLSCOM_MCBUSYQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCBUSYQ;
#endif
    return fapi2::getScom(i_target, ATCL_CL_CLSCOM_MCBUSYQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ATCL_CL_CLSCOM_MCBUSYQ(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return fapi2::putScom(i_target, ATCL_CL_CLSCOM_MCBUSYQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT,
           ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT,
           ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT,
           ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0,
           ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0,
           ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0,
           ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1,
           ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1,
           ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1,
           ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2,
           ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2,
           ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2,
           ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43,
           ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43,
           ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43,
           ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ATCL_CL_CLSCOM_MCPERF3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCPERF3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ATCL_CL_CLSCOM_MCPERF3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCPERF3;
#endif
    return fapi2::getScom(i_target, ATCL_CL_CLSCOM_MCPERF3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ATCL_CL_CLSCOM_MCPERF3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return fapi2::putScom(i_target, ATCL_CL_CLSCOM_MCPERF3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00,
           ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00,
           ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00,
           ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01,
           ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01,
           ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01,
           ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10,
           ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10,
           ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10,
           ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11,
           ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11,
           ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11,
           ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0,
           ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0,
           ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0,
           ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1,
           ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1,
           ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1,
           ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2,
           ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2,
           ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2,
           ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3,
           ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3,
           ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3,
           ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_RESERVED_34_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_RESERVED_34_36,
           ATCL_CL_CLSCOM_MCPERF3_RESERVED_34_36_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED_34_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_RESERVED_34_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_RESERVED_34_36,
           ATCL_CL_CLSCOM_MCPERF3_RESERVED_34_36_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED_34_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_RESERVED_34_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_RESERVED_34_36,
           ATCL_CL_CLSCOM_MCPERF3_RESERVED_34_36_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED_34_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_RESERVED44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_RESERVED44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_RESERVED44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_RESERVED44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_RESERVED44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_RESERVED44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_RESERVED44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_RESERVED44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_RESERVED44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_RESERVED44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_RESERVED44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_RESERVED44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL,
           ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL,
           ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL,
           ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL,
           ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL,
           ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL,
           ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH,
           ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH,
           ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH,
           ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CRYPTO_ENCRYPT_CRYPTOKEY1A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_ENCRYPT_CRYPTOKEY1A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CRYPTO_ENCRYPT_CRYPTOKEY1A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CRYPTO_ENCRYPT_CRYPTOKEY1A;
#endif
    return fapi2::getScom(i_target, CRYPTO_ENCRYPT_CRYPTOKEY1A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CRYPTO_ENCRYPT_CRYPTOKEY1A(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOKEY1A));
#endif
    return fapi2::putScom(i_target, CRYPTO_ENCRYPT_CRYPTOKEY1A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOKEY1A));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A,
           CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOKEY1A));
#endif
    return o_data.insertFromRight<CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A,
           CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CRYPTO_ENCRYPT_CRYPTOKEY1A));
#endif
    return i_data.extractToRight<CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A,
           CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLINJ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLINJ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLINJ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLINJ;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLINJ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLINJ(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLINJ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLINJ_ERR_INJ_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.insertFromRight<DSTL_DSTLINJ_ERR_INJ_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLINJ_ERR_INJ_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.insertFromRight<DSTL_DSTLINJ_ERR_INJ_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLINJ_ERR_INJ_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.setBit<DSTL_DSTLINJ_ERR_INJ_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLINJ_ERR_INJ_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.clearBit<DSTL_DSTLINJ_ERR_INJ_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLINJ_ERR_INJ_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return i_data.extractToRight<DSTL_DSTLINJ_ERR_INJ_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLINJ_ERR_INJ_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return i_data.getBit<DSTL_DSTLINJ_ERR_INJ_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLINJ_ERR_INJ_CONT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.insertFromRight<DSTL_DSTLINJ_ERR_INJ_CONT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_CONT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLINJ_ERR_INJ_CONT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.insertFromRight<DSTL_DSTLINJ_ERR_INJ_CONT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_CONT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLINJ_ERR_INJ_CONT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.setBit<DSTL_DSTLINJ_ERR_INJ_CONT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_CONT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLINJ_ERR_INJ_CONT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.clearBit<DSTL_DSTLINJ_ERR_INJ_CONT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_CONT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLINJ_ERR_INJ_CONT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return i_data.extractToRight<DSTL_DSTLINJ_ERR_INJ_CONT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_CONT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLINJ_ERR_INJ_CONT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return i_data.getBit<DSTL_DSTLINJ_ERR_INJ_CONT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_CONT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLINJ_ERR_INJ_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.insertFromRight<DSTL_DSTLINJ_ERR_INJ_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLINJ_ERR_INJ_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.insertFromRight<DSTL_DSTLINJ_ERR_INJ_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLINJ_ERR_INJ_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.setBit<DSTL_DSTLINJ_ERR_INJ_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLINJ_ERR_INJ_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.clearBit<DSTL_DSTLINJ_ERR_INJ_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLINJ_ERR_INJ_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return i_data.extractToRight<DSTL_DSTLINJ_ERR_INJ_TYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLINJ_ERR_INJ_TYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return i_data.getBit<DSTL_DSTLINJ_ERR_INJ_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.insertFromRight<DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.insertFromRight<DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.setBit<DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.clearBit<DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return i_data.extractToRight<DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return i_data.getBit<DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_ERR_INJ_SUBCH_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLINJ_RESERVED_4_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.insertFromRight<DSTL_DSTLINJ_RESERVED_4_15,
           DSTL_DSTLINJ_RESERVED_4_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_RESERVED_4_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLINJ_RESERVED_4_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return o_data.insertFromRight<DSTL_DSTLINJ_RESERVED_4_15,
           DSTL_DSTLINJ_RESERVED_4_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_RESERVED_4_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLINJ_RESERVED_4_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLINJ));
#endif
    return i_data.extractToRight<DSTL_DSTLINJ_RESERVED_4_15,
           DSTL_DSTLINJ_RESERVED_4_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLINJ_RESERVED_4_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_WRITE_READCFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WRITE_READCFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_WRITE_READCFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WRITE_READCFG;
#endif
    return fapi2::getScom(i_target, WRITE_READCFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_WRITE_READCFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return fapi2::putScom(i_target, WRITE_READCFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_RD_EINJ_TARGET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_RD_EINJ_TARGET,
           WRITE_READCFG_CFG_RD_EINJ_TARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_RD_EINJ_TARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_RD_EINJ_TARGET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_RD_EINJ_TARGET,
           WRITE_READCFG_CFG_RD_EINJ_TARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_RD_EINJ_TARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_CFG_RD_EINJ_TARGET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_CFG_RD_EINJ_TARGET,
           WRITE_READCFG_CFG_RD_EINJ_TARGET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_RD_EINJ_TARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_RD_EINJ_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_RD_EINJ_RATE,
           WRITE_READCFG_CFG_RD_EINJ_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_RD_EINJ_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_RD_EINJ_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_RD_EINJ_RATE,
           WRITE_READCFG_CFG_RD_EINJ_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_RD_EINJ_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_CFG_RD_EINJ_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_CFG_RD_EINJ_RATE,
           WRITE_READCFG_CFG_RD_EINJ_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_RD_EINJ_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_RD_FAIL_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_RD_FAIL_ACTION,
           WRITE_READCFG_CFG_RD_FAIL_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_RD_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_RD_FAIL_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_RD_FAIL_ACTION,
           WRITE_READCFG_CFG_RD_FAIL_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_RD_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_CFG_RD_FAIL_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_CFG_RD_FAIL_ACTION,
           WRITE_READCFG_CFG_RD_FAIL_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_RD_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_READCFG_RESERVED_9_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_READCFG_RESERVED_9_11,
           WRITE_READCFG_READCFG_RESERVED_9_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_RESERVED_9_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_READCFG_RESERVED_9_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_READCFG_RESERVED_9_11,
           WRITE_READCFG_READCFG_RESERVED_9_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_RESERVED_9_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_READCFG_RESERVED_9_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_READCFG_RESERVED_9_11,
           WRITE_READCFG_READCFG_RESERVED_9_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_RESERVED_9_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_RTYFAIL_NO_BD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_RTYFAIL_NO_BD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_RTYFAIL_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_RTYFAIL_NO_BD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_RTYFAIL_NO_BD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_RTYFAIL_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_RTYFAIL_NO_BD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_CFG_RTYFAIL_NO_BD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_RTYFAIL_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_CFG_RTYFAIL_NO_BD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_CFG_RTYFAIL_NO_BD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_RTYFAIL_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_CFG_RTYFAIL_NO_BD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_CFG_RTYFAIL_NO_BD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_RTYFAIL_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_READCFG_CFG_RTYFAIL_NO_BD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_CFG_RTYFAIL_NO_BD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_RTYFAIL_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_BOGUS_NO_BD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_BOGUS_NO_BD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_BOGUS_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_BOGUS_NO_BD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_BOGUS_NO_BD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_BOGUS_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_BOGUS_NO_BD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_CFG_BOGUS_NO_BD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_BOGUS_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_CFG_BOGUS_NO_BD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_CFG_BOGUS_NO_BD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_BOGUS_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_CFG_BOGUS_NO_BD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_CFG_BOGUS_NO_BD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_BOGUS_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_READCFG_CFG_BOGUS_NO_BD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_CFG_BOGUS_NO_BD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_BOGUS_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD,
           WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD,
           WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD,
           WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD,
           WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD,
           WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD,
           WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_READCFG_RESERVED_34_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_READCFG_RESERVED_34_39,
           WRITE_READCFG_READCFG_RESERVED_34_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_RESERVED_34_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_READCFG_RESERVED_34_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_READCFG_RESERVED_34_39,
           WRITE_READCFG_READCFG_RESERVED_34_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_RESERVED_34_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_READCFG_RESERVED_34_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_READCFG_RESERVED_34_39,
           WRITE_READCFG_READCFG_RESERVED_34_39_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_READCFG_READCFG_RESERVED_34_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_WRITE_WRT_DSTL_ECC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WRITE_WRT_DSTL_ECC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_WRITE_WRT_DSTL_ECC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WRITE_WRT_DSTL_ECC;
#endif
    return fapi2::getScom(i_target, WRITE_WRT_DSTL_ECC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_WRITE_WRT_DSTL_ECC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return fapi2::putScom(i_target, WRITE_WRT_DSTL_ECC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_DSTL_ECC_0_ERR_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_DSTL_ECC_0_ERR_TYPE,
           WRITE_WRT_DSTL_ECC_0_ERR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_0_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_DSTL_ECC_0_ERR_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_DSTL_ECC_0_ERR_TYPE,
           WRITE_WRT_DSTL_ECC_0_ERR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_0_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRT_DSTL_ECC_0_ERR_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return i_data.extractToRight<WRITE_WRT_DSTL_ECC_0_ERR_TYPE,
           WRITE_WRT_DSTL_ECC_0_ERR_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_0_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_DSTL_ECC_0_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_DSTL_ECC_0_SYNDROME,
           WRITE_WRT_DSTL_ECC_0_SYNDROME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_0_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_DSTL_ECC_0_SYNDROME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_DSTL_ECC_0_SYNDROME,
           WRITE_WRT_DSTL_ECC_0_SYNDROME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_0_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRT_DSTL_ECC_0_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return i_data.extractToRight<WRITE_WRT_DSTL_ECC_0_SYNDROME,
           WRITE_WRT_DSTL_ECC_0_SYNDROME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_0_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_DSTL_ECC_1_ERR_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_DSTL_ECC_1_ERR_TYPE,
           WRITE_WRT_DSTL_ECC_1_ERR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_1_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_DSTL_ECC_1_ERR_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_DSTL_ECC_1_ERR_TYPE,
           WRITE_WRT_DSTL_ECC_1_ERR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_1_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRT_DSTL_ECC_1_ERR_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return i_data.extractToRight<WRITE_WRT_DSTL_ECC_1_ERR_TYPE,
           WRITE_WRT_DSTL_ECC_1_ERR_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_1_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_DSTL_ECC_1_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_DSTL_ECC_1_SYNDROME,
           WRITE_WRT_DSTL_ECC_1_SYNDROME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_1_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_DSTL_ECC_1_SYNDROME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_DSTL_ECC_1_SYNDROME,
           WRITE_WRT_DSTL_ECC_1_SYNDROME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_1_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRT_DSTL_ECC_1_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return i_data.extractToRight<WRITE_WRT_DSTL_ECC_1_SYNDROME,
           WRITE_WRT_DSTL_ECC_1_SYNDROME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_1_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_DSTL_ECC_2_ERR_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_DSTL_ECC_2_ERR_TYPE,
           WRITE_WRT_DSTL_ECC_2_ERR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_2_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_DSTL_ECC_2_ERR_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_DSTL_ECC_2_ERR_TYPE,
           WRITE_WRT_DSTL_ECC_2_ERR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_2_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRT_DSTL_ECC_2_ERR_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return i_data.extractToRight<WRITE_WRT_DSTL_ECC_2_ERR_TYPE,
           WRITE_WRT_DSTL_ECC_2_ERR_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_2_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_DSTL_ECC_2_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_DSTL_ECC_2_SYNDROME,
           WRITE_WRT_DSTL_ECC_2_SYNDROME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_2_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_DSTL_ECC_2_SYNDROME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_DSTL_ECC_2_SYNDROME,
           WRITE_WRT_DSTL_ECC_2_SYNDROME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_2_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRT_DSTL_ECC_2_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return i_data.extractToRight<WRITE_WRT_DSTL_ECC_2_SYNDROME,
           WRITE_WRT_DSTL_ECC_2_SYNDROME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_2_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_DSTL_ECC_3_ERR_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_DSTL_ECC_3_ERR_TYPE,
           WRITE_WRT_DSTL_ECC_3_ERR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_3_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_DSTL_ECC_3_ERR_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_DSTL_ECC_3_ERR_TYPE,
           WRITE_WRT_DSTL_ECC_3_ERR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_3_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRT_DSTL_ECC_3_ERR_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return i_data.extractToRight<WRITE_WRT_DSTL_ECC_3_ERR_TYPE,
           WRITE_WRT_DSTL_ECC_3_ERR_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_3_ERR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_DSTL_ECC_3_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_DSTL_ECC_3_SYNDROME,
           WRITE_WRT_DSTL_ECC_3_SYNDROME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_3_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_WRT_DSTL_ECC_3_SYNDROME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return o_data.insertFromRight<WRITE_WRT_DSTL_ECC_3_SYNDROME,
           WRITE_WRT_DSTL_ECC_3_SYNDROME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_3_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_WRT_DSTL_ECC_3_SYNDROME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_WRT_DSTL_ECC));
#endif
    return i_data.extractToRight<WRITE_WRT_DSTL_ECC_3_SYNDROME,
           WRITE_WRT_DSTL_ECC_3_SYNDROME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_WRT_DSTL_ECC_3_SYNDROME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
