/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00007.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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


//>> PREP_[ATCL_CL_CLSCOM_MCBUSYQ]
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
//<< PREP_[ATCL_CL_CLSCOM_MCBUSYQ]

//>> GET_[ATCL_CL_CLSCOM_MCBUSYQ]
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
//<< GET_[ATCL_CL_CLSCOM_MCBUSYQ]

//>> PUT_[ATCL_CL_CLSCOM_MCBUSYQ]
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
//<< PUT_[ATCL_CL_CLSCOM_MCBUSYQ]


//>> SET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS]

//>> SET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS]

//>> SET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS]

//>> CLEAR_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS]

//>> GET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS]

//>> GET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS]
static inline bool GET_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS]

//>> SET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT]

//>> SET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT]

//>> GET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT]

//>> SET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0]

//>> SET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0]

//>> GET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0]

//>> SET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1]

//>> SET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1]

//>> GET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1]

//>> SET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2]

//>> SET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2]

//>> GET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2]

//>> SET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY]

//>> SET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY]

//>> SET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY]

//>> CLEAR_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY]

//>> GET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY]

//>> GET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY]
static inline bool GET_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_AGGRESSIVE_BUSY]

//>> SET_[ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43,
           ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43]

//>> SET_[ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43,
           ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43]

//>> GET_[ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43,
           ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_43]

//>> SET_[P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37]
static inline fapi2::buffer<uint64_t>& SET_P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37,
           P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37]

//>> SET_[P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37]
static inline fapi2::buffer<uint64_t>& SET_P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37,
           P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37]

//>> GET_[P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37]
static inline fapi2::buffer<uint64_t>& GET_P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return i_data.extractToRight<P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37,
           P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_ATCL_CL_CLSCOM_MCBUSYQ_RSVD_35_37]

//>> SET_[P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20]
static inline fapi2::buffer<uint64_t>& SET_P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20,
           P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20]

//>> SET_[P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20]
static inline fapi2::buffer<uint64_t>& SET_P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return o_data.insertFromRight<P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20,
           P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20]

//>> GET_[P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20]
static inline fapi2::buffer<uint64_t>& GET_P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCBUSYQ));
#endif
    return i_data.extractToRight<P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20,
           P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_ATCL_CL_CLSCOM_MCBUSYQ_EARLY_HANG_CNTL_P10D20]

//>> PREP_[ATCL_CL_CLSCOM_MCPERF3]
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
//<< PREP_[ATCL_CL_CLSCOM_MCPERF3]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3]
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
//<< GET_[ATCL_CL_CLSCOM_MCPERF3]

//>> PUT_[ATCL_CL_CLSCOM_MCPERF3]
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
//<< PUT_[ATCL_CL_CLSCOM_MCPERF3]


//>> SET_[ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_EN_DROP_PLS_F_FULL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_DIS_DROPABLE_HP]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_EN_PF_CONF_RETRY]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV00]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV01]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV10]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_DROP_PLS_DIV11]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH0]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH1]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH2]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_PF_CONF_RETRY_THRESH3]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_WRBUF_DONE_EQ_WRITE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_RMWBUF_DONE_EQ_WRITE]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_EN_MDI_UPDATE_MIRROR_DCBZ_TM]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36,
           ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36,
           ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36,
           ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_RESERVED_35_36]

//>> SET_[P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36]
static inline fapi2::buffer<uint64_t>& SET_P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36,
           P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36]

//>> SET_[P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36]
static inline fapi2::buffer<uint64_t>& SET_P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36,
           P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36]

//>> GET_[P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36]
static inline fapi2::buffer<uint64_t>& GET_P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36,
           P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_ATCL_CL_CLSCOM_MCPERF3_SPARE_35_36]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_HP_PF_EQ_LP_RD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_LP_PF_EQ_RD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CRESP_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_RMW_BUF_DEALLOC_STALL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_PROMOTE_RESET_DROP]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_READ_HIT_AMO_WINDOW]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_RESERVED44]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_RESERVED44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_RESERVED44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_RESERVED44]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_RESERVED44]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_RESERVED44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_RESERVED44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_RESERVED44]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_RESERVED44]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_RESERVED44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_RESERVED44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_RESERVED44]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_RESERVED44]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_RESERVED44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_RESERVED44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_RESERVED44]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_RESERVED44]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_RESERVED44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_RESERVED44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_RESERVED44]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_RESERVED44]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_RESERVED44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_RESERVED44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_RESERVED44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_RESERVED44]

//>> SET_[P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20]
static inline fapi2::buffer<uint64_t>& SET_P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20]

//>> SET_[P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20]
static inline fapi2::buffer<uint64_t>& SET_P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20]

//>> SET_[P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20]
static inline fapi2::buffer<uint64_t>& SET_P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20]

//>> CLEAR_[P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20]

//>> GET_[P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20]
static inline fapi2::buffer<uint64_t>& GET_P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20]

//>> GET_[P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20]
static inline bool GET_P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_ATCL_CL_CLSCOM_MCPERF3_EN_HWFM_RETRY_ALT_P10D20]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W]
static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_128B_CI_PR_W]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_LP_RD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_HP_WR_EQ_RD]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_NSQ_LOC0_CNT_SEL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_SQ_LOC0_CNT_SEL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_RETRY]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_TIMEOUT_FORCE_CH_FAIL]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_DISABLE_RETRY_AMO_HPC_WR_BAD_CR]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN]
static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN]

//>> CLEAR_[ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN]
static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN]
static inline bool GET_ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCPERF3));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_EN_INBAND_NO_DISP_WIN]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH]
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
    FAPI_ERR("0:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH]

//>> SET_[ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH]
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
    FAPI_ERR("1:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH]

//>> GET_[ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH]
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
    FAPI_ERR("4:scom_mcc Invalid dial access ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATCL_CL_CLSCOM_MCPERF3_INBAND_NO_DISP_THRESH]

//>> PREP_[CRYPTO_ENCRYPT_CRYPTOKEY1A]
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
//<< PREP_[CRYPTO_ENCRYPT_CRYPTOKEY1A]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOKEY1A]
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
//<< GET_[CRYPTO_ENCRYPT_CRYPTOKEY1A]

//>> PUT_[CRYPTO_ENCRYPT_CRYPTOKEY1A]
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
//<< PUT_[CRYPTO_ENCRYPT_CRYPTOKEY1A]


//>> SET_[CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A]
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
    FAPI_ERR("0:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A]

//>> SET_[CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A]
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
    FAPI_ERR("1:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A]

//>> GET_[CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A]
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
    FAPI_ERR("4:scom_mcc Invalid dial access CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CRYPTO_ENCRYPT_CRYPTOKEY1A_KEY1A]

//>> PREP_[WRITE_READCFG]
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
//<< PREP_[WRITE_READCFG]

//>> GET_[WRITE_READCFG]
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
//<< GET_[WRITE_READCFG]

//>> PUT_[WRITE_READCFG]
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
//<< PUT_[WRITE_READCFG]


//>> SET_[WRITE_READCFG_CFG_RD_EINJ_TARGET]
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
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_CFG_RD_EINJ_TARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_RD_EINJ_TARGET]

//>> SET_[WRITE_READCFG_CFG_RD_EINJ_TARGET]
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
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_CFG_RD_EINJ_TARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_RD_EINJ_TARGET]

//>> GET_[WRITE_READCFG_CFG_RD_EINJ_TARGET]
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
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_CFG_RD_EINJ_TARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_RD_EINJ_TARGET]

//>> SET_[WRITE_READCFG_CFG_RD_EINJ_RATE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_CFG_RD_EINJ_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_RD_EINJ_RATE]

//>> SET_[WRITE_READCFG_CFG_RD_EINJ_RATE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_CFG_RD_EINJ_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_RD_EINJ_RATE]

//>> GET_[WRITE_READCFG_CFG_RD_EINJ_RATE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_CFG_RD_EINJ_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_RD_EINJ_RATE]

//>> SET_[WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER]
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
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER]

//>> SET_[WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER]
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
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER]

//>> SET_[WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER]

//>> CLEAR_[WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER]

//>> GET_[WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER]
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
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER]

//>> GET_[WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER]
static inline bool GET_WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_DISABLE_EARLY_TRIGGER]

//>> SET_[WRITE_READCFG_CFG_RD_FAIL_ACTION]
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
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_CFG_RD_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_RD_FAIL_ACTION]

//>> SET_[WRITE_READCFG_CFG_RD_FAIL_ACTION]
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
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_CFG_RD_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_RD_FAIL_ACTION]

//>> GET_[WRITE_READCFG_CFG_RD_FAIL_ACTION]
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
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_CFG_RD_FAIL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_RD_FAIL_ACTION]

//>> SET_[WRITE_READCFG_READCFG_RESERVED_9_11]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_READCFG_RESERVED_9_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_READCFG_RESERVED_9_11,
           WRITE_READCFG_READCFG_RESERVED_9_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_READCFG_RESERVED_9_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_READCFG_RESERVED_9_11]

//>> SET_[WRITE_READCFG_READCFG_RESERVED_9_11]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_READCFG_RESERVED_9_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_READCFG_RESERVED_9_11,
           WRITE_READCFG_READCFG_RESERVED_9_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_READCFG_RESERVED_9_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_READCFG_RESERVED_9_11]

//>> GET_[WRITE_READCFG_READCFG_RESERVED_9_11]
static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_READCFG_RESERVED_9_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_READCFG_RESERVED_9_11,
           WRITE_READCFG_READCFG_RESERVED_9_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_READCFG_RESERVED_9_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_READCFG_RESERVED_9_11]

//>> SET_[P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE,
           P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE]

//>> SET_[P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE,
           P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE]

//>> GET_[P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE,
           P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_MODE]

//>> SET_[P10_20_WRITE_READCFG_READCFG_RESERVED_11]
static inline fapi2::buffer<uint64_t>& SET_P10_20_WRITE_READCFG_READCFG_RESERVED_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<P10_20_WRITE_READCFG_READCFG_RESERVED_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access P10_20_WRITE_READCFG_READCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_WRITE_READCFG_READCFG_RESERVED_11]

//>> SET_[P10_20_WRITE_READCFG_READCFG_RESERVED_11]
static inline fapi2::buffer<uint64_t>& SET_P10_20_WRITE_READCFG_READCFG_RESERVED_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<P10_20_WRITE_READCFG_READCFG_RESERVED_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access P10_20_WRITE_READCFG_READCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_WRITE_READCFG_READCFG_RESERVED_11]

//>> SET_[P10_20_WRITE_READCFG_READCFG_RESERVED_11]
static inline fapi2::buffer<uint64_t>& SET_P10_20_WRITE_READCFG_READCFG_RESERVED_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<P10_20_WRITE_READCFG_READCFG_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access P10_20_WRITE_READCFG_READCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_WRITE_READCFG_READCFG_RESERVED_11]

//>> CLEAR_[P10_20_WRITE_READCFG_READCFG_RESERVED_11]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_WRITE_READCFG_READCFG_RESERVED_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<P10_20_WRITE_READCFG_READCFG_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access P10_20_WRITE_READCFG_READCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_WRITE_READCFG_READCFG_RESERVED_11]

//>> GET_[P10_20_WRITE_READCFG_READCFG_RESERVED_11]
static inline fapi2::buffer<uint64_t>& GET_P10_20_WRITE_READCFG_READCFG_RESERVED_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<P10_20_WRITE_READCFG_READCFG_RESERVED_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access P10_20_WRITE_READCFG_READCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_WRITE_READCFG_READCFG_RESERVED_11]

//>> GET_[P10_20_WRITE_READCFG_READCFG_RESERVED_11]
static inline bool GET_P10_20_WRITE_READCFG_READCFG_RESERVED_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<P10_20_WRITE_READCFG_READCFG_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access P10_20_WRITE_READCFG_READCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_WRITE_READCFG_READCFG_RESERVED_11]

//>> SET_[WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA]
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
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA]

//>> SET_[WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA]
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
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA]

//>> SET_[WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA]

//>> CLEAR_[WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA]
static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA]

//>> GET_[WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA]
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
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA]

//>> GET_[WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA]
static inline bool GET_WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_MMIO_SUE_BAD_DATA]

//>> SET_[WRITE_READCFG_CFG_RTYFAIL_NO_BD]
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
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_CFG_RTYFAIL_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_RTYFAIL_NO_BD]

//>> SET_[WRITE_READCFG_CFG_RTYFAIL_NO_BD]
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
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_CFG_RTYFAIL_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_RTYFAIL_NO_BD]

//>> SET_[WRITE_READCFG_CFG_RTYFAIL_NO_BD]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_RTYFAIL_NO_BD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_CFG_RTYFAIL_NO_BD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access WRITE_READCFG_CFG_RTYFAIL_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_RTYFAIL_NO_BD]

//>> CLEAR_[WRITE_READCFG_CFG_RTYFAIL_NO_BD]
static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_CFG_RTYFAIL_NO_BD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_CFG_RTYFAIL_NO_BD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access WRITE_READCFG_CFG_RTYFAIL_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[WRITE_READCFG_CFG_RTYFAIL_NO_BD]

//>> GET_[WRITE_READCFG_CFG_RTYFAIL_NO_BD]
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
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_CFG_RTYFAIL_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_RTYFAIL_NO_BD]

//>> GET_[WRITE_READCFG_CFG_RTYFAIL_NO_BD]
static inline bool GET_WRITE_READCFG_CFG_RTYFAIL_NO_BD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_CFG_RTYFAIL_NO_BD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access WRITE_READCFG_CFG_RTYFAIL_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_RTYFAIL_NO_BD]

//>> SET_[WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME]
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
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME]

//>> SET_[WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME]
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
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME]

//>> SET_[WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME]

//>> CLEAR_[WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME]
static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME]

//>> GET_[WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME]
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
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME]

//>> GET_[WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME]
static inline bool GET_WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_READCFG_CAPTURE_1ST_SYNDROME]

//>> SET_[WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE]
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
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE]

//>> SET_[WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE]
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
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE]

//>> SET_[WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE]

//>> CLEAR_[WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE]

//>> GET_[WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE]
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
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE]

//>> GET_[WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE]
static inline bool GET_WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_READCFG_SYNDROME_FIR_ENABLE]

//>> SET_[WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS]
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
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS]

//>> SET_[WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS]
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
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS]

//>> SET_[WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS]

//>> CLEAR_[WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS]
static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS]

//>> GET_[WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS]
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
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS]

//>> GET_[WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS]
static inline bool GET_WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_BYPASS_SUPPORT_64B_FAILS]

//>> SET_[WRITE_READCFG_CFG_BOGUS_NO_BD]
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
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_CFG_BOGUS_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_BOGUS_NO_BD]

//>> SET_[WRITE_READCFG_CFG_BOGUS_NO_BD]
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
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_CFG_BOGUS_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_BOGUS_NO_BD]

//>> SET_[WRITE_READCFG_CFG_BOGUS_NO_BD]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_BOGUS_NO_BD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_CFG_BOGUS_NO_BD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access WRITE_READCFG_CFG_BOGUS_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_BOGUS_NO_BD]

//>> CLEAR_[WRITE_READCFG_CFG_BOGUS_NO_BD]
static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_CFG_BOGUS_NO_BD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_CFG_BOGUS_NO_BD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access WRITE_READCFG_CFG_BOGUS_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[WRITE_READCFG_CFG_BOGUS_NO_BD]

//>> GET_[WRITE_READCFG_CFG_BOGUS_NO_BD]
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
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_CFG_BOGUS_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_BOGUS_NO_BD]

//>> GET_[WRITE_READCFG_CFG_BOGUS_NO_BD]
static inline bool GET_WRITE_READCFG_CFG_BOGUS_NO_BD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_CFG_BOGUS_NO_BD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access WRITE_READCFG_CFG_BOGUS_NO_BD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_BOGUS_NO_BD]

//>> SET_[WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS]
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
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS]

//>> SET_[WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS]
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
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS]

//>> SET_[WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS]

//>> CLEAR_[WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS]
static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS]

//>> GET_[WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS]
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
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS]

//>> GET_[WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS]
static inline bool GET_WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_DO_DUAL_PACKET_ANALYSIS]

//>> SET_[WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD]
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
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD]

//>> SET_[WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD]
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
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD]

//>> GET_[WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD]
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
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_P1PF_DROP_THRESHOLD]

//>> SET_[WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ]
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
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ]

//>> SET_[WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ]
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
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ]

//>> SET_[WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.setBit<WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mcc Invalid dial access WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ]

//>> CLEAR_[WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ]
static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.clearBit<WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mcc Invalid dial access WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ]

//>> GET_[WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ]
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
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ]

//>> GET_[WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ]
static inline bool GET_WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.getBit<WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mcc Invalid dial access WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_P1PF_EN_PEND_ADJ]

//>> SET_[WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD]
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
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD]

//>> SET_[WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD]
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
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD]

//>> GET_[WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD]
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
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_P1PF_STOP_THRESHOLD]

//>> SET_[WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT,
           WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT]

//>> SET_[WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT,
           WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT]

//>> GET_[WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT]
static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT,
           WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_RD_WAT_FASTPATH_EVENT]

//>> SET_[WRITE_READCFG_CFG_RD_WAT_STALL_EVENT]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_RD_WAT_STALL_EVENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_RD_WAT_STALL_EVENT,
           WRITE_READCFG_CFG_RD_WAT_STALL_EVENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_CFG_RD_WAT_STALL_EVENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_RD_WAT_STALL_EVENT]

//>> SET_[WRITE_READCFG_CFG_RD_WAT_STALL_EVENT]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_CFG_RD_WAT_STALL_EVENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_CFG_RD_WAT_STALL_EVENT,
           WRITE_READCFG_CFG_RD_WAT_STALL_EVENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_CFG_RD_WAT_STALL_EVENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_CFG_RD_WAT_STALL_EVENT]

//>> GET_[WRITE_READCFG_CFG_RD_WAT_STALL_EVENT]
static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_CFG_RD_WAT_STALL_EVENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_CFG_RD_WAT_STALL_EVENT,
           WRITE_READCFG_CFG_RD_WAT_STALL_EVENT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_CFG_RD_WAT_STALL_EVENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_CFG_RD_WAT_STALL_EVENT]

//>> SET_[WRITE_READCFG_READCFG_RESERVED_38_39]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_READCFG_RESERVED_38_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_READCFG_RESERVED_38_39,
           WRITE_READCFG_READCFG_RESERVED_38_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access WRITE_READCFG_READCFG_RESERVED_38_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_READCFG_RESERVED_38_39]

//>> SET_[WRITE_READCFG_READCFG_RESERVED_38_39]
static inline fapi2::buffer<uint64_t>& SET_WRITE_READCFG_READCFG_RESERVED_38_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<WRITE_READCFG_READCFG_RESERVED_38_39,
           WRITE_READCFG_READCFG_RESERVED_38_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access WRITE_READCFG_READCFG_RESERVED_38_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[WRITE_READCFG_READCFG_RESERVED_38_39]

//>> GET_[WRITE_READCFG_READCFG_RESERVED_38_39]
static inline fapi2::buffer<uint64_t>& GET_WRITE_READCFG_READCFG_RESERVED_38_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<WRITE_READCFG_READCFG_RESERVED_38_39,
           WRITE_READCFG_READCFG_RESERVED_38_39_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access WRITE_READCFG_READCFG_RESERVED_38_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[WRITE_READCFG_READCFG_RESERVED_38_39]

//>> SET_[P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS,
           P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mcc Invalid dial access P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS]

//>> SET_[P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return o_data.insertFromRight<P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS,
           P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mcc Invalid dial access P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS]

//>> GET_[P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS]
static inline fapi2::buffer<uint64_t>& GET_P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(WRITE_READCFG));
#endif
    return i_data.extractToRight<P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS,
           P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mcc Invalid dial access P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_WRITE_READCFG_CFG_DD2_OVERCOMMIT_CREDITS]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
