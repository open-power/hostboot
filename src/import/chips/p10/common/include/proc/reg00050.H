/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00050.H $         */
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

#ifndef __PROC_REG00050_H_
#define __PROC_REG00050_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_FIRMASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010833;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_FIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010833;
#endif
    return fapi2::getScom(i_target, INT_CQ_FIRMASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_FIRMASK_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010835, 0x2010834, 0x2010833));
#endif
    return fapi2::putScom(i_target, INT_CQ_FIRMASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_FIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010834;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_FIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010834;
#endif
    return fapi2::getScom(i_target, INT_CQ_FIRMASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_FIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010835, 0x2010834, 0x2010833));
#endif
    return fapi2::putScom(i_target, INT_CQ_FIRMASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_FIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010835;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_FIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010835;
#endif
    return fapi2::getScom(i_target, INT_CQ_FIRMASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_FIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010835, 0x2010834, 0x2010833));
#endif
    return fapi2::putScom(i_target, INT_CQ_FIRMASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIRMASK_INT_CQ_FIRMASK_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010835, 0x2010834, 0x2010833));
#endif
    return o_data.insertFromRight<INT_CQ_FIRMASK_INT_CQ_FIRMASK_FIR_MASK,
           INT_CQ_FIRMASK_INT_CQ_FIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIRMASK_INT_CQ_FIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIRMASK_INT_CQ_FIRMASK_FIR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010835, 0x2010834, 0x2010833));
#endif
    return o_data.insertFromRight<INT_CQ_FIRMASK_INT_CQ_FIRMASK_FIR_MASK,
           INT_CQ_FIRMASK_INT_CQ_FIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIRMASK_INT_CQ_FIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIRMASK_INT_CQ_FIRMASK_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010835, 0x2010834, 0x2010833));
#endif
    return i_data.extractToRight<INT_CQ_FIRMASK_INT_CQ_FIRMASK_FIR_MASK,
           INT_CQ_FIRMASK_INT_CQ_FIRMASK_FIR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIRMASK_INT_CQ_FIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_PMC_5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201082d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_PMC_5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201082d;
#endif
    return fapi2::getScom(i_target, INT_CQ_PMC_5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_PMC_5(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201082d));
#endif
    return fapi2::putScom(i_target, INT_CQ_PMC_5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PMC_5_INT_CQ_PMC_5_COUNT_0_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201082d));
#endif
    return o_data.insertFromRight<INT_CQ_PMC_5_INT_CQ_PMC_5_COUNT_0_47,
           INT_CQ_PMC_5_INT_CQ_PMC_5_COUNT_0_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PMC_5_INT_CQ_PMC_5_COUNT_0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PMC_5_INT_CQ_PMC_5_COUNT_0_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201082d));
#endif
    return o_data.insertFromRight<INT_CQ_PMC_5_INT_CQ_PMC_5_COUNT_0_47,
           INT_CQ_PMC_5_INT_CQ_PMC_5_COUNT_0_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PMC_5_INT_CQ_PMC_5_COUNT_0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_PMC_5_INT_CQ_PMC_5_COUNT_0_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201082d));
#endif
    return i_data.extractToRight<INT_CQ_PMC_5_INT_CQ_PMC_5_COUNT_0_47,
           INT_CQ_PMC_5_INT_CQ_PMC_5_COUNT_0_47_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PMC_5_INT_CQ_PMC_5_COUNT_0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_SWI_RSP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010825;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_SWI_RSP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010825;
#endif
    return fapi2::getScom(i_target, INT_CQ_SWI_RSP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_SWI_RSP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return fapi2::putScom(i_target, INT_CQ_SWI_RSP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_HIST_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_HIST_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_HIST_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_HIST_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_HIST_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_HIST_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_HIST_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.setBit<INT_CQ_SWI_RSP_HIST_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_HIST_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_SWI_RSP_HIST_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.clearBit<INT_CQ_SWI_RSP_HIST_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_HIST_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_SWI_RSP_HIST_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.extractToRight<INT_CQ_SWI_RSP_HIST_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_HIST_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_SWI_RSP_HIST_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.getBit<INT_CQ_SWI_RSP_HIST_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_HIST_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_POLL_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_POLL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_POLL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_POLL_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_POLL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_POLL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_POLL_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.setBit<INT_CQ_SWI_RSP_POLL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_POLL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_SWI_RSP_POLL_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.clearBit<INT_CQ_SWI_RSP_POLL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_POLL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_SWI_RSP_POLL_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.extractToRight<INT_CQ_SWI_RSP_POLL_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_POLL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_SWI_RSP_POLL_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.getBit<INT_CQ_SWI_RSP_POLL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_POLL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_BCAST_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_BCAST_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_BCAST_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_BCAST_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_BCAST_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_BCAST_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_BCAST_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.setBit<INT_CQ_SWI_RSP_BCAST_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_BCAST_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_SWI_RSP_BCAST_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.clearBit<INT_CQ_SWI_RSP_BCAST_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_BCAST_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_SWI_RSP_BCAST_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.extractToRight<INT_CQ_SWI_RSP_BCAST_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_BCAST_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_SWI_RSP_BCAST_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.getBit<INT_CQ_SWI_RSP_BCAST_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_BCAST_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_ASSIGN_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_ASSIGN_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_ASSIGN_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_ASSIGN_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_ASSIGN_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_ASSIGN_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_ASSIGN_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.setBit<INT_CQ_SWI_RSP_ASSIGN_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_ASSIGN_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_SWI_RSP_ASSIGN_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.clearBit<INT_CQ_SWI_RSP_ASSIGN_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_ASSIGN_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_SWI_RSP_ASSIGN_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.extractToRight<INT_CQ_SWI_RSP_ASSIGN_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_ASSIGN_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_SWI_RSP_ASSIGN_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.getBit<INT_CQ_SWI_RSP_ASSIGN_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_ASSIGN_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_BLK_UPDT_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_BLK_UPDT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_BLK_UPDT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_BLK_UPDT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_BLK_UPDT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_BLK_UPDT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_BLK_UPDT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.setBit<INT_CQ_SWI_RSP_BLK_UPDT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_BLK_UPDT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_SWI_RSP_BLK_UPDT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.clearBit<INT_CQ_SWI_RSP_BLK_UPDT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_BLK_UPDT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_SWI_RSP_BLK_UPDT_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.extractToRight<INT_CQ_SWI_RSP_BLK_UPDT_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_BLK_UPDT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_SWI_RSP_BLK_UPDT_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.getBit<INT_CQ_SWI_RSP_BLK_UPDT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_BLK_UPDT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_Z(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_Z,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_Z chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_Z(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_Z,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_Z chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_Z(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.setBit<INT_CQ_SWI_RSP_Z>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_Z chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_SWI_RSP_Z(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.clearBit<INT_CQ_SWI_RSP_Z>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_Z chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_SWI_RSP_Z(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.extractToRight<INT_CQ_SWI_RSP_Z,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_Z chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_SWI_RSP_Z(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.getBit<INT_CQ_SWI_RSP_Z>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_Z chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_O(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_O,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_O chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_O(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_O,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_O chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_O(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.setBit<INT_CQ_SWI_RSP_O>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_O chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_SWI_RSP_O(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.clearBit<INT_CQ_SWI_RSP_O>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_O chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_SWI_RSP_O(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.extractToRight<INT_CQ_SWI_RSP_O,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_O chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_SWI_RSP_O(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.getBit<INT_CQ_SWI_RSP_O>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_O chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_M(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_M,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_M chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_M(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_M,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_M chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_M(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.setBit<INT_CQ_SWI_RSP_M>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_M chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_SWI_RSP_M(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.clearBit<INT_CQ_SWI_RSP_M>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_M chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_SWI_RSP_M(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.extractToRight<INT_CQ_SWI_RSP_M,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_M chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_SWI_RSP_M(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.getBit<INT_CQ_SWI_RSP_M>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_M chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_CRESP_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_CRESP_0_4,
           INT_CQ_SWI_RSP_CRESP_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_CRESP_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_CRESP_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_CRESP_0_4,
           INT_CQ_SWI_RSP_CRESP_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_CRESP_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_SWI_RSP_CRESP_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.extractToRight<INT_CQ_SWI_RSP_CRESP_0_4,
           INT_CQ_SWI_RSP_CRESP_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_CRESP_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_CRESP_RAMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_CRESP_RAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_CRESP_RAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_CRESP_RAMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_CRESP_RAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_CRESP_RAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_CRESP_RAMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.setBit<INT_CQ_SWI_RSP_CRESP_RAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_CRESP_RAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_SWI_RSP_CRESP_RAMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.clearBit<INT_CQ_SWI_RSP_CRESP_RAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_CRESP_RAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_SWI_RSP_CRESP_RAMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.extractToRight<INT_CQ_SWI_RSP_CRESP_RAMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_CRESP_RAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_SWI_RSP_CRESP_RAMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.getBit<INT_CQ_SWI_RSP_CRESP_RAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_CRESP_RAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_COLLISON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_COLLISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_COLLISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_COLLISON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_COLLISON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_COLLISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_COLLISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.setBit<INT_CQ_SWI_RSP_COLLISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_COLLISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_SWI_RSP_COLLISON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.clearBit<INT_CQ_SWI_RSP_COLLISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_COLLISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_SWI_RSP_COLLISON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.extractToRight<INT_CQ_SWI_RSP_COLLISON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_COLLISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_SWI_RSP_COLLISON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.getBit<INT_CQ_SWI_RSP_COLLISON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_COLLISON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_PRECLUDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_PRECLUDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_PRECLUDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_PRECLUDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_PRECLUDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_PRECLUDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_PRECLUDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.setBit<INT_CQ_SWI_RSP_PRECLUDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_PRECLUDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_SWI_RSP_PRECLUDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.clearBit<INT_CQ_SWI_RSP_PRECLUDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_PRECLUDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_SWI_RSP_PRECLUDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.extractToRight<INT_CQ_SWI_RSP_PRECLUDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_PRECLUDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_SWI_RSP_PRECLUDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.getBit<INT_CQ_SWI_RSP_PRECLUDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_PRECLUDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_ATAG_0_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_ATAG_0_15,
           INT_CQ_SWI_RSP_ATAG_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_ATAG_0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_SWI_RSP_ATAG_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return o_data.insertFromRight<INT_CQ_SWI_RSP_ATAG_0_15,
           INT_CQ_SWI_RSP_ATAG_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_ATAG_0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_SWI_RSP_ATAG_0_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010825));
#endif
    return i_data.extractToRight<INT_CQ_SWI_RSP_ATAG_0_15,
           INT_CQ_SWI_RSP_ATAG_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_SWI_RSP_ATAG_0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_ADDITIONAL_PERF_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a9b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a9b;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_ADDITIONAL_PERF_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_ADDITIONAL_PERF_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_ADDITIONAL_PERF_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P0_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_P1_IS_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_2_9(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_2_9,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_2_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_2_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_2_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_2_9,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_2_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_2_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_2_9(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_2_9,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_2_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_2_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_PTAG_IN_USE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_16_27(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_16_27,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_16_27_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_16_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_16_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_16_27,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_16_27_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_16_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_16_27(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_16_27,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_16_27_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_16_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_UNLOCK_IN_FIFO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_32_33(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_32_33,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_32_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_32_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_32_33,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_32_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_32_33(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_32_33,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_32_33_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_32_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_OUTSTANDING_WB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_OUTSTANDING_WB,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_OUTSTANDING_WB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_OUTSTANDING_WB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_OUTSTANDING_WB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_OUTSTANDING_WB,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_OUTSTANDING_WB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_OUTSTANDING_WB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_OUTSTANDING_WB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_OUTSTANDING_WB,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_OUTSTANDING_WB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_OUTSTANDING_WB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_40_41(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_40_41,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_40_41_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_40_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_40_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_40_41,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_40_41_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_40_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_40_41(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_40_41,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_40_41_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_RESERVED_40_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_WAY_NUMBER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_WAY_NUMBER,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_WAY_NUMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_WAY_NUMBER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_WAY_NUMBER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_WAY_NUMBER,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_WAY_NUMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_WAY_NUMBER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_WAY_NUMBER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9b));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_WAY_NUMBER,
           INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_WAY_NUMBER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_ADDITIONAL_PERF_1_MAX_WAY_NUMBER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_WATCH0_SPEC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010aa0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_WATCH0_SPEC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010aa0;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_WATCH0_SPEC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_WATCH0_SPEC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010aa0));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_WATCH0_SPEC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_WATCH2_DATA1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010ab5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_WATCH2_DATA1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010ab5;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_WATCH2_DATA1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_WATCH2_DATA1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010ab5));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_WATCH2_DATA1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_WATCH_ASSIGN(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a86;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_WATCH_ASSIGN(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a86;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_WATCH_ASSIGN, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_WATCH_ASSIGN(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010a86));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_WATCH_ASSIGN, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_AIB_TX_CRD(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a14;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_AIB_TX_CRD(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a14;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_AIB_TX_CRD, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_AIB_TX_CRD(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_AIB_TX_CRD, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.setBit<INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.clearBit<INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.getBit<INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_CRD_INIT_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RESERVED_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RESERVED_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RESERVED_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RESERVED_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RESERVED_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.setBit<INT_PC_REGS_AIB_TX_CRD_RESERVED_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_AIB_TX_CRD_RESERVED_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.clearBit<INT_PC_REGS_AIB_TX_CRD_RESERVED_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_TX_CRD_RESERVED_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_TX_CRD_RESERVED_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_AIB_TX_CRD_RESERVED_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.getBit<INT_PC_REGS_AIB_TX_CRD_RESERVED_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_READ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_READ,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_READ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_READ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_READ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_READ,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_READ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_READ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_READ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_READ,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_READ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_READ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_NCKO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_NCKO,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_NCKO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_NCKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_NCKO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_NCKO,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_NCKO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_NCKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_NCKO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_NCKO,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_NCKO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_NCKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_AT_MACRO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_AT_MACRO,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_AT_MACRO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_AT_MACRO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_AT_MACRO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_AT_MACRO,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_AT_MACRO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_AT_MACRO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_AT_MACRO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_AT_MACRO,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_AT_MACRO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_AT_MACRO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_CHKO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_CHKO,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_CHKO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_CHKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_CHKO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_CHKO,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_CHKO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_CHKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_CHKO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_CHKO,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_CHKO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_PC_CHKO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_READ_CRD_POOL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_READ_CRD_POOL,
           INT_PC_REGS_AIB_TX_CRD_READ_CRD_POOL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_READ_CRD_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_READ_CRD_POOL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_READ_CRD_POOL,
           INT_PC_REGS_AIB_TX_CRD_READ_CRD_POOL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_READ_CRD_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_TX_CRD_READ_CRD_POOL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_TX_CRD_READ_CRD_POOL,
           INT_PC_REGS_AIB_TX_CRD_READ_CRD_POOL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_READ_CRD_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_VC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_VC,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_VC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_VC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_VC,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_VC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_VC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_VC,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_VC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_LD_RMT_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RESERVED_42_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RESERVED_42_45,
           INT_PC_REGS_AIB_TX_CRD_RESERVED_42_45_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RESERVED_42_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RESERVED_42_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RESERVED_42_45,
           INT_PC_REGS_AIB_TX_CRD_RESERVED_42_45_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RESERVED_42_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_TX_CRD_RESERVED_42_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_TX_CRD_RESERVED_42_45,
           INT_PC_REGS_AIB_TX_CRD_RESERVED_42_45_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RESERVED_42_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_SYNC_WRITE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_SYNC_WRITE,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_SYNC_WRITE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_SYNC_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_SYNC_WRITE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_SYNC_WRITE,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_SYNC_WRITE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_SYNC_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_SYNC_WRITE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_SYNC_WRITE,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_SYNC_WRITE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_SYNC_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_TCTXT_WRITE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_TCTXT_WRITE,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_TCTXT_WRITE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_TCTXT_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_TCTXT_WRITE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_TCTXT_WRITE,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_TCTXT_WRITE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_TCTXT_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_TCTXT_WRITE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_TCTXT_WRITE,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_TCTXT_WRITE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_TCTXT_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_CHKI(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_CHKI,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_CHKI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_CHKI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_CHKI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_CHKI,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_CHKI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_CHKI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_CHKI(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_CHKI,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_CHKI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_CHKI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_WRITE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_WRITE,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_WRITE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_WRITE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_WRITE,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_WRITE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_WRITE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_WRITE,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_WRITE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_DMA_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_NCKI(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_NCKI,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_NCKI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_NCKI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_NCKI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_NCKI,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_NCKI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_NCKI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_NCKI(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_NCKI,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_NCKI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_PC_NCKI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_VC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_VC,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_VC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_VC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_VC,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_VC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_VC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_VC,
           INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_VC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_RSD_CRD_NXC_ST_RMT_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_WRITE_CRD_POOL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_WRITE_CRD_POOL,
           INT_PC_REGS_AIB_TX_CRD_WRITE_CRD_POOL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_WRITE_CRD_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AIB_TX_CRD_WRITE_CRD_POOL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AIB_TX_CRD_WRITE_CRD_POOL,
           INT_PC_REGS_AIB_TX_CRD_WRITE_CRD_POOL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_WRITE_CRD_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AIB_TX_CRD_WRITE_CRD_POOL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a14));
#endif
    return i_data.extractToRight<INT_PC_REGS_AIB_TX_CRD_WRITE_CRD_POOL,
           INT_PC_REGS_AIB_TX_CRD_WRITE_CRD_POOL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AIB_TX_CRD_WRITE_CRD_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_NRQ_PEND_ARB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a1d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_NRQ_PEND_ARB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a1d;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_NRQ_PEND_ARB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_NRQ_PEND_ARB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_NRQ_PEND_ARB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_RESERVED_0_1,
           INT_PC_REGS_NRQ_PEND_ARB_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_RESERVED_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_RESERVED_0_1,
           INT_PC_REGS_NRQ_PEND_ARB_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_NRQ_PEND_ARB_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return i_data.extractToRight<INT_PC_REGS_NRQ_PEND_ARB_RESERVED_0_1,
           INT_PC_REGS_NRQ_PEND_ARB_RESERVED_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_LOAD_RR_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_LOAD_RR_SEL,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_LOAD_RR_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_LOAD_RR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_LOAD_RR_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_LOAD_RR_SEL,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_LOAD_RR_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_LOAD_RR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_LOAD_RR_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return i_data.extractToRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_LOAD_RR_SEL,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_LOAD_RR_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_LOAD_RR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_STORE_RR_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_STORE_RR_SEL,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_STORE_RR_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_STORE_RR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_STORE_RR_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_STORE_RR_SEL,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_STORE_RR_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_STORE_RR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_STORE_RR_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return i_data.extractToRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_STORE_RR_SEL,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_STORE_RR_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_PARSE_STORE_RR_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_RESERVED_6_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_RESERVED_6_7,
           INT_PC_REGS_NRQ_PEND_ARB_RESERVED_6_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_RESERVED_6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_RESERVED_6_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_RESERVED_6_7,
           INT_PC_REGS_NRQ_PEND_ARB_RESERVED_6_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_RESERVED_6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_NRQ_PEND_ARB_RESERVED_6_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return i_data.extractToRight<INT_PC_REGS_NRQ_PEND_ARB_RESERVED_6_7,
           INT_PC_REGS_NRQ_PEND_ARB_RESERVED_6_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_RESERVED_6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKO_LD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKO_LD,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKO_LD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKO_LD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKO_LD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKO_LD,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKO_LD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKO_LD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKO_LD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return i_data.extractToRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKO_LD,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKO_LD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKO_LD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKO_LD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKO_LD,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKO_LD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKO_LD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKO_LD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKO_LD,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKO_LD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKO_LD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKO_LD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return i_data.extractToRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKO_LD,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKO_LD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKO_LD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKI_ST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKI_ST,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKI_ST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKI_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKI_ST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKI_ST,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKI_ST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKI_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKI_ST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return i_data.extractToRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKI_ST,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKI_ST_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_NCKI_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKI_ST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKI_ST,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKI_ST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKI_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKI_ST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKI_ST,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKI_ST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKI_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKI_ST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return i_data.extractToRight<INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKI_ST,
           INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKI_ST_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_CFG_NRQ_PEND_ARB_PRIO_CHKI_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_RESERVED_16_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_RESERVED_16_23,
           INT_PC_REGS_NRQ_PEND_ARB_RESERVED_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_RESERVED_16_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NRQ_PEND_ARB_RESERVED_16_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NRQ_PEND_ARB_RESERVED_16_23,
           INT_PC_REGS_NRQ_PEND_ARB_RESERVED_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_RESERVED_16_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_NRQ_PEND_ARB_RESERVED_16_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a1d));
#endif
    return i_data.extractToRight<INT_PC_REGS_NRQ_PEND_ARB_RESERVED_16_23,
           INT_PC_REGS_NRQ_PEND_ARB_RESERVED_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NRQ_PEND_ARB_RESERVED_16_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_NVG_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a0d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_NVG_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a0d;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_NVG_BLOCK_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_NVG_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010a0d));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_NVG_BLOCK_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NVG_BLOCK_MODE_INT_PC_NVG_BLOCK_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a0d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NVG_BLOCK_MODE_INT_PC_NVG_BLOCK_MODE,
           INT_PC_REGS_NVG_BLOCK_MODE_INT_PC_NVG_BLOCK_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NVG_BLOCK_MODE_INT_PC_NVG_BLOCK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_NVG_BLOCK_MODE_INT_PC_NVG_BLOCK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a0d));
#endif
    return o_data.insertFromRight<INT_PC_REGS_NVG_BLOCK_MODE_INT_PC_NVG_BLOCK_MODE,
           INT_PC_REGS_NVG_BLOCK_MODE_INT_PC_NVG_BLOCK_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NVG_BLOCK_MODE_INT_PC_NVG_BLOCK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_NVG_BLOCK_MODE_INT_PC_NVG_BLOCK_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a0d));
#endif
    return i_data.extractToRight<INT_PC_REGS_NVG_BLOCK_MODE_INT_PC_NVG_BLOCK_MODE,
           INT_PC_REGS_NVG_BLOCK_MODE_INT_PC_NVG_BLOCK_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_NVG_BLOCK_MODE_INT_PC_NVG_BLOCK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_TCTXT_LSI_SET_01(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010b25;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_TCTXT_LSI_SET_01(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010b25;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_TCTXT_LSI_SET_01, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_TCTXT_LSI_SET_01(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010b25));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_TCTXT_LSI_SET_01, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_WATCH1_DATA3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20109af;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_WATCH1_DATA3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20109af;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_WATCH1_DATA3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_WATCH1_DATA3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20109af));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_WATCH1_DATA3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_QUEUES_CFG_REM_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010919;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_QUEUES_CFG_REM_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010919;
#endif
    return fapi2::getScom(i_target, INT_VC_QUEUES_CFG_REM_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_QUEUES_CFG_REM_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return fapi2::putScom(i_target, INT_VC_QUEUES_CFG_REM_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_PREFETCH_DISTANCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_PREFETCH_DISTANCE,
           INT_VC_QUEUES_CFG_REM_2_IRQ_PREFETCH_DISTANCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_PREFETCH_DISTANCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_PREFETCH_DISTANCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_PREFETCH_DISTANCE,
           INT_VC_QUEUES_CFG_REM_2_IRQ_PREFETCH_DISTANCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_PREFETCH_DISTANCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_IRQ_PREFETCH_DISTANCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_IRQ_PREFETCH_DISTANCE,
           INT_VC_QUEUES_CFG_REM_2_IRQ_PREFETCH_DISTANCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_PREFETCH_DISTANCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_RESERVED_8_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_8_10,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_8_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_8_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_RESERVED_8_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_8_10,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_8_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_8_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_RESERVED_8_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_8_10,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_8_10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_8_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_CQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_CQ,
           INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_CQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_CQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_CQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_CQ,
           INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_CQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_CQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_CQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_CQ,
           INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_CQ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_CQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_RESERVED_16_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_16_18,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_16_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_16_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_RESERVED_16_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_16_18,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_16_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_16_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_RESERVED_16_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_16_18,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_16_18_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_16_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_PC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_PC,
           INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_PC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_PC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_PC,
           INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_PC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_PC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_PC,
           INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_PC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_CRD_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_NB_OUTSTANDING_DEM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_NB_OUTSTANDING_DEM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_MAX_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_MIN_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_MIN_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_2_IRQ_MIN_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_MIN_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_MIN_NB_OUTSTANDING_DEM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_MIN_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_2_IRQ_MIN_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_MIN_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_IRQ_MIN_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_IRQ_MIN_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_2_IRQ_MIN_NB_OUTSTANDING_DEM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_MIN_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_32_33,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_RESERVED_32_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_32_33,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_32_33,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_32_33_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_2_IRQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_2_IRQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_2_IRQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_IRQ_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_IRQ_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_2_IRQ_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_2_IRQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_RESERVED_36_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_36_37,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_36_37_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_36_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_RESERVED_36_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_36_37,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_36_37_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_36_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_RESERVED_36_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_36_37,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_36_37_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_36_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_RESERVED_40_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_40_41,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_40_41_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_RESERVED_40_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_40_41,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_40_41_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_RESERVED_40_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_40_41,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_40_41_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_MEM_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_ERQ_MEM_SIZE,
           INT_VC_QUEUES_CFG_REM_2_ERQ_MEM_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_MEM_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_ERQ_MEM_SIZE,
           INT_VC_QUEUES_CFG_REM_2_ERQ_MEM_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_ERQ_MEM_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_ERQ_MEM_SIZE,
           INT_VC_QUEUES_CFG_REM_2_ERQ_MEM_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_RESERVED_48_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_48_49,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_48_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_RESERVED_48_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_48_49,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_48_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_RESERVED_48_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_RESERVED_48_49,
           INT_VC_QUEUES_CFG_REM_2_RESERVED_48_49_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_ERQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_ERQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_2_ERQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_2_ERQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_2_ERQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_ERQ_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_ERQ_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_2_ERQ_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_2_ERQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010919));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_2_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_QUEUES_PERF_EVENT_SEL_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010927;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_QUEUES_PERF_EVENT_SEL_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010927;
#endif
    return fapi2::getScom(i_target, INT_VC_QUEUES_PERF_EVENT_SEL_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_QUEUES_PERF_EVENT_SEL_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return fapi2::putScom(i_target, INT_VC_QUEUES_PERF_EVENT_SEL_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_1_FROM_AIB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_FROM_AIB,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_FROM_AIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_FROM_AIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_1_FROM_AIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_FROM_AIB,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_FROM_AIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_FROM_AIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_1_FROM_AIB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_FROM_AIB,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_FROM_AIB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_FROM_AIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_1_IRQ_TO_IQA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_IRQ_TO_IQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_IRQ_TO_IQA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_IRQ_TO_IQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_1_IRQ_TO_IQA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_IRQ_TO_IQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_IRQ_TO_IQA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_IRQ_TO_IQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_1_IRQ_TO_IQA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_IRQ_TO_IQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_IRQ_TO_IQA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_IRQ_TO_IQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_DPS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_DPS,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_DPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_DPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_DPS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_DPS,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_DPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_DPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_DPS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_DPS,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_DPS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_DPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_IQS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_IQS,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_IQS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_IQS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_IQS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_IQS,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_IQS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_IQS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_IQS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_IQS,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_IQS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_IQA_TO_IQS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_1_IQS_TO_EQA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_IQS_TO_EQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_IQS_TO_EQA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_IQS_TO_EQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_1_IQS_TO_EQA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_IQS_TO_EQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_IQS_TO_EQA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_IQS_TO_EQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_1_IQS_TO_EQA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_IQS_TO_EQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_IQS_TO_EQA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_IQS_TO_EQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ERQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ERQ,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ERQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ERQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ERQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ERQ,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ERQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ERQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ERQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ERQ,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ERQ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ERQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ATX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ATX,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ATX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ATX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ATX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ATX,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ATX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ATX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ATX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ATX,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ATX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ATX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ENDC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ENDC,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ENDC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ENDC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ENDC,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ENDC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ENDC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010927));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ENDC,
           INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ENDC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_1_EQA_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_RECOV_ERR_G2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20109d5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_RECOV_ERR_G2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20109d5;
#endif
    return fapi2::getScom(i_target, INT_VC_RECOV_ERR_G2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_RECOV_ERR_G2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20109d5));
#endif
    return fapi2::putScom(i_target, INT_VC_RECOV_ERR_G2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_RECOV_ERR_G2_INT_VC_RECOV_ERR_G2_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20109d5));
#endif
    return o_data.insertFromRight<INT_VC_RECOV_ERR_G2_INT_VC_RECOV_ERR_G2_ERROR,
           INT_VC_RECOV_ERR_G2_INT_VC_RECOV_ERR_G2_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_RECOV_ERR_G2_INT_VC_RECOV_ERR_G2_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_RECOV_ERR_G2_INT_VC_RECOV_ERR_G2_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20109d5));
#endif
    return o_data.insertFromRight<INT_VC_RECOV_ERR_G2_INT_VC_RECOV_ERR_G2_ERROR,
           INT_VC_RECOV_ERR_G2_INT_VC_RECOV_ERR_G2_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_RECOV_ERR_G2_INT_VC_RECOV_ERR_G2_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_RECOV_ERR_G2_INT_VC_RECOV_ERR_G2_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20109d5));
#endif
    return i_data.extractToRight<INT_VC_RECOV_ERR_G2_INT_VC_RECOV_ERR_G2_ERROR,
           INT_VC_RECOV_ERR_G2_INT_VC_RECOV_ERR_G2_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_RECOV_ERR_G2_INT_VC_RECOV_ERR_G2_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_WOF_ERR_G0_DETAIL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20109c3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_WOF_ERR_G0_DETAIL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20109c3;
#endif
    return fapi2::getScom(i_target, INT_VC_WOF_ERR_G0_DETAIL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_WOF_ERR_G0_DETAIL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20109c3));
#endif
    return fapi2::putScom(i_target, INT_VC_WOF_ERR_G0_DETAIL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_DETAIL_INT_VC_WOF_ERR_G0_DETAIL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20109c3));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_DETAIL_INT_VC_WOF_ERR_G0_DETAIL_ERROR,
           INT_VC_WOF_ERR_G0_DETAIL_INT_VC_WOF_ERR_G0_DETAIL_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_DETAIL_INT_VC_WOF_ERR_G0_DETAIL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_WOF_ERR_G0_DETAIL_INT_VC_WOF_ERR_G0_DETAIL_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20109c3));
#endif
    return o_data.insertFromRight<INT_VC_WOF_ERR_G0_DETAIL_INT_VC_WOF_ERR_G0_DETAIL_ERROR,
           INT_VC_WOF_ERR_G0_DETAIL_INT_VC_WOF_ERR_G0_DETAIL_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_DETAIL_INT_VC_WOF_ERR_G0_DETAIL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_WOF_ERR_G0_DETAIL_INT_VC_WOF_ERR_G0_DETAIL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20109c3));
#endif
    return i_data.extractToRight<INT_VC_WOF_ERR_G0_DETAIL_INT_VC_WOF_ERR_G0_DETAIL_ERROR,
           INT_VC_WOF_ERR_G0_DETAIL_INT_VC_WOF_ERR_G0_DETAIL_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_WOF_ERR_G0_DETAIL_INT_VC_WOF_ERR_G0_DETAIL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_CFG_NMMU_CTL_TLB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c55;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_CFG_NMMU_CTL_TLB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c55;
#endif
    return fapi2::getScom(i_target, MM0_MM_CFG_NMMU_CTL_TLB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_CFG_NMMU_CTL_TLB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return fapi2::putScom(i_target, MM0_MM_CFG_NMMU_CTL_TLB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_MBR_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_MBR_DIS,
           MM0_MM_CFG_NMMU_CTL_TLB_MBR_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MBR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_MBR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_MBR_DIS,
           MM0_MM_CFG_NMMU_CTL_TLB_MBR_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MBR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_MBR_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_MBR_DIS,
           MM0_MM_CFG_NMMU_CTL_TLB_MBR_DIS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MBR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SNGL_THD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_CAC_ALLOC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DMAP_MODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_HASH_LPID_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DIR_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_CAC_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_LRU_PERR_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MULTIHIT_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_EA_RANGE_CHK_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS426_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS486_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS505_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS510_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS512_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL,
           MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL,
           MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL,
           MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS0_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL,
           MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL,
           MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL,
           MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_DBG_BUS1_STG0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS534_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS537_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS540_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS543_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ,
           MM0_MM_CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ,
           MM0_MM_CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ,
           MM0_MM_CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_GUEST_PREF_PGSZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ,
           MM0_MM_CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ,
           MM0_MM_CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ,
           MM0_MM_CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_HOST_PREF_PGSZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS542_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS567_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_ISS586_FIX_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_MPSS_PREF_PGSZ_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_TWSM_11_1_MODE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SNGL_SHOT_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c55));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_TLB_SLB_SNGL_SHOT_HOLDOFF_ENA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c1d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c1d;
#endif
    return fapi2::getScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return fapi2::putScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return o_data.setBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return o_data.clearBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c1d));
#endif
    return i_data.getBit<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c06;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c06;
#endif
    return fapi2::getScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c06));
#endif
    return fapi2::putScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c06));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c06));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c06));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c07;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c07;
#endif
    return fapi2::getScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c07));
#endif
    return fapi2::putScom(i_target, MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c07));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c07));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c07));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1,
           MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c24;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c24;
#endif
    return fapi2::getScom(i_target, MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c24));
#endif
    return fapi2::putScom(i_target, MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c24));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63,
           MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c24));
#endif
    return o_data.insertFromRight<MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63,
           MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c24));
#endif
    return i_data.extractToRight<MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63,
           MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_CH4_ADDR_6_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011147;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_CH4_ADDR_6_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011147;
#endif
    return fapi2::getScom(i_target, NX_CH4_ADDR_6_HASH_FUNCTION_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_CH4_ADDR_6_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011147));
#endif
    return fapi2::putScom(i_target, NX_CH4_ADDR_6_HASH_FUNCTION_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_CH4_ADDR_6_HASH_FUNCTION_REG_ADDRESS_6_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011147));
#endif
    return o_data.insertFromRight<NX_CH4_ADDR_6_HASH_FUNCTION_REG_ADDRESS_6_HASH_FUNCTION,
           NX_CH4_ADDR_6_HASH_FUNCTION_REG_ADDRESS_6_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_6_HASH_FUNCTION_REG_ADDRESS_6_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_ADDR_6_HASH_FUNCTION_REG_ADDRESS_6_HASH_FUNCTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011147));
#endif
    return o_data.insertFromRight<NX_CH4_ADDR_6_HASH_FUNCTION_REG_ADDRESS_6_HASH_FUNCTION,
           NX_CH4_ADDR_6_HASH_FUNCTION_REG_ADDRESS_6_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_6_HASH_FUNCTION_REG_ADDRESS_6_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_ADDR_6_HASH_FUNCTION_REG_ADDRESS_6_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011147));
#endif
    return i_data.extractToRight<NX_CH4_ADDR_6_HASH_FUNCTION_REG_ADDRESS_6_HASH_FUNCTION,
           NX_CH4_ADDR_6_HASH_FUNCTION_REG_ADDRESS_6_HASH_FUNCTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_6_HASH_FUNCTION_REG_ADDRESS_6_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_CH4_DATATAG_2_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201114e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_CH4_DATATAG_2_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201114e;
#endif
    return fapi2::getScom(i_target, NX_CH4_DATATAG_2_HASH_FUNCTION_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_CH4_DATATAG_2_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201114e));
#endif
    return fapi2::putScom(i_target, NX_CH4_DATATAG_2_HASH_FUNCTION_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_CH4_DATATAG_2_HASH_FUNCTION_REG_DATATAG_2_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201114e));
#endif
    return o_data.insertFromRight<NX_CH4_DATATAG_2_HASH_FUNCTION_REG_DATATAG_2_HASH_FUNCTION,
           NX_CH4_DATATAG_2_HASH_FUNCTION_REG_DATATAG_2_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_DATATAG_2_HASH_FUNCTION_REG_DATATAG_2_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_DATATAG_2_HASH_FUNCTION_REG_DATATAG_2_HASH_FUNCTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201114e));
#endif
    return o_data.insertFromRight<NX_CH4_DATATAG_2_HASH_FUNCTION_REG_DATATAG_2_HASH_FUNCTION,
           NX_CH4_DATATAG_2_HASH_FUNCTION_REG_DATATAG_2_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_DATATAG_2_HASH_FUNCTION_REG_DATATAG_2_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_DATATAG_2_HASH_FUNCTION_REG_DATATAG_2_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201114e));
#endif
    return i_data.extractToRight<NX_CH4_DATATAG_2_HASH_FUNCTION_REG_DATATAG_2_HASH_FUNCTION,
           NX_CH4_DATATAG_2_HASH_FUNCTION_REG_DATATAG_2_HASH_FUNCTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_DATATAG_2_HASH_FUNCTION_REG_DATATAG_2_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201108d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x201108d;
#endif
    return fapi2::getScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x201108d));
#endif
    return fapi2::putScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201108d));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201108d));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201108d));
#endif
    return i_data.extractToRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201108d));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201108d));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201108d));
#endif
    return o_data.setBit<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201108d));
#endif
    return o_data.clearBit<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201108d));
#endif
    return i_data.extractToRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x201108d));
#endif
    return i_data.getBit<NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011090;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011090;
#endif
    return fapi2::getScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011090));
#endif
    return fapi2::putScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG_NXCQ_TRACE_CNTL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011090));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG_NXCQ_TRACE_CNTL,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG_NXCQ_TRACE_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG_NXCQ_TRACE_CNTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG_NXCQ_TRACE_CNTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011090));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG_NXCQ_TRACE_CNTL,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG_NXCQ_TRACE_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG_NXCQ_TRACE_CNTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG_NXCQ_TRACE_CNTL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011090));
#endif
    return i_data.extractToRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG_NXCQ_TRACE_CNTL,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG_NXCQ_TRACE_CNTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_PB_DEBUG_REG_NXCQ_TRACE_CNTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_RNG_ST3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110e8;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_RNG_ST3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110e8;
#endif
    return fapi2::getScom(i_target, NX_PBI_RNG_ST3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_RNG_ST3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20110e8));
#endif
    return fapi2::putScom(i_target, NX_PBI_RNG_ST3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_RRN_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110e8));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST3_RRN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST3_RRN_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_RRN_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110e8));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST3_RRN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST3_RRN_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_RRN_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110e8));
#endif
    return o_data.setBit<NX_PBI_RNG_ST3_RRN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST3_RRN_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_ST3_RRN_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110e8));
#endif
    return o_data.clearBit<NX_PBI_RNG_ST3_RRN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST3_RRN_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST3_RRN_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110e8));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST3_RRN_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST3_RRN_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_ST3_RRN_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110e8));
#endif
    return i_data.getBit<NX_PBI_RNG_ST3_RRN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST3_RRN_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_WINDOW_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110e8));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST3_WINDOW_SIZE,
           NX_PBI_RNG_ST3_WINDOW_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST3_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_WINDOW_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110e8));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST3_WINDOW_SIZE,
           NX_PBI_RNG_ST3_WINDOW_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST3_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST3_WINDOW_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110e8));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST3_WINDOW_SIZE,
           NX_PBI_RNG_ST3_WINDOW_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST3_WINDOW_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_MATCH_TH_MIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110e8));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST3_MATCH_TH_MIN,
           NX_PBI_RNG_ST3_MATCH_TH_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST3_MATCH_TH_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_MATCH_TH_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110e8));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST3_MATCH_TH_MIN,
           NX_PBI_RNG_ST3_MATCH_TH_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST3_MATCH_TH_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST3_MATCH_TH_MIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110e8));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST3_MATCH_TH_MIN,
           NX_PBI_RNG_ST3_MATCH_TH_MIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST3_MATCH_TH_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_MATCH_TH_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110e8));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST3_MATCH_TH_MAX,
           NX_PBI_RNG_ST3_MATCH_TH_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST3_MATCH_TH_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST3_MATCH_TH_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110e8));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST3_MATCH_TH_MAX,
           NX_PBI_RNG_ST3_MATCH_TH_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST3_MATCH_TH_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST3_MATCH_TH_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110e8));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST3_MATCH_TH_MAX,
           NX_PBI_RNG_ST3_MATCH_TH_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST3_MATCH_TH_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110cc;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110cc;
#endif
    return fapi2::getScom(i_target, NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20110cc));
#endif
    return fapi2::putScom(i_target, NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cc));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cc));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cc));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_READ_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_QUEUED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cc));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_QUEUED,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_QUEUED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_QUEUED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_QUEUED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cc));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_QUEUED,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_QUEUED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_QUEUED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_QUEUED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cc));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_QUEUED,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_QUEUED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_CNTL_QUEUED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110c8;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110c8;
#endif
    return fapi2::getScom(i_target, NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20110c8));
#endif
    return fapi2::putScom(i_target, NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_LPID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c8));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_LPID,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_LPID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_LPID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_LPID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c8));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_LPID,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_LPID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_LPID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_LPID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c8));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_LPID,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_LPID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_LPID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_PID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c8));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_PID,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_PID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_PID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_PID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c8));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_PID,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_PID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_PID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_PID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c8));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_PID,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_PID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_PID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_TID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c8));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_TID,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_TID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_TID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_TID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c8));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_TID,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_TID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_TID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_TID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c8));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_TID,
           NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_TID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_TID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c8));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c8));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c8));
#endif
    return o_data.setBit<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c8));
#endif
    return o_data.clearBit<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c8));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c8));
#endif
    return i_data.getBit<NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110cb;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110cb;
#endif
    return fapi2::getScom(i_target, NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20110cb));
#endif
    return fapi2::putScom(i_target, NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cb));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR,
           NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cb));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR,
           NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cb));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR,
           NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cb));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_SIZE,
           NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_SIZE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_SIZE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cb));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_SIZE,
           NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_SIZE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110cb));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_SIZE,
           NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_GZIP_LO_PRIOR_RCV_FIFO_BAR_GZIP_LO_PRIORITY_RCV_FIFO_BAR_SIZE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_ES3_HP_MODE1_CURR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x38c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_ES3_HP_MODE1_CURR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x38c;
#endif
    return fapi2::getScom(i_target, PB_COM_ES3_HP_MODE1_CURR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_ES3_HP_MODE1_CURR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return fapi2::putScom(i_target, PB_COM_ES3_HP_MODE1_CURR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_MASTER_CHIP_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_TM_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_GP_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_CHG_RATE_SP_MASTER_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_AGGREGATE_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_G_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_AGGREGATE_CURR_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.setBit<PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return o_data.clearBit<PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.extractToRight<PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x38c));
#endif
    return i_data.getBit<PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_HP_MODE1_CURR_R_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_DOB23_DIB23_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1001182a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_DOB23_DIB23_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1001182a;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_DOB23_DIB23_INT_ERR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_DOB23_DIB23_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1001182a));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_DOB23_DIB23_INT_ERR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_MAILBOX_20_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011834;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_MAILBOX_20_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011834;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_MAILBOX_20_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_MAILBOX_20_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10011834));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_MAILBOX_20_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_MAILBOX_21_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011835;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_MAILBOX_21_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011835;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_MAILBOX_21_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_MAILBOX_21_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10011835));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_MAILBOX_21_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_MAILBOX_CTL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1001182e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_MAILBOX_CTL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1001182e;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_MAILBOX_CTL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_MAILBOX_CTL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_MAILBOX_CTL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.setBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.getBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.setBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.getBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_WR_NOT_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.setBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.getBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.setBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.getBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.setBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.getBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_CORRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.setBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.getBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.setBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.getBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_BAD_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.setBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.getBit<PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.setBit<PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.clearBit<PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.getBit<PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_AILBOX_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_ID,
           PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_ID,
           PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_ID,
           PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_LINK_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_SPARE,
           PB_PTLSCOM10_MAILBOX_CTL_REG_B_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_SPARE,
           PB_PTLSCOM10_MAILBOX_CTL_REG_B_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_MAILBOX_CTL_REG_B_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1001182e));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_MAILBOX_CTL_REG_B_SPARE,
           PB_PTLSCOM10_MAILBOX_CTL_REG_B_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_MAILBOX_CTL_REG_B_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PMU3_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011824;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PMU3_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011824;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PMU3_CNPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PMU3_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10011824));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PMU3_CNPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PSAVE23_MODE_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011816;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PSAVE23_MODE_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011816;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PSAVE23_MODE_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PSAVE23_MODE_CFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10011816));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PSAVE23_MODE_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE23_MODE_CFG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE23_MODE_CFG_MODE,
           PB_PTLSCOM10_PSAVE23_MODE_CFG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE23_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE23_MODE_CFG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE23_MODE_CFG_MODE,
           PB_PTLSCOM10_PSAVE23_MODE_CFG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE23_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PSAVE23_MODE_CFG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011816));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PSAVE23_MODE_CFG_MODE,
           PB_PTLSCOM10_PSAVE23_MODE_CFG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE23_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE23_MODE_CFG_WIDTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE23_MODE_CFG_WIDTH,
           PB_PTLSCOM10_PSAVE23_MODE_CFG_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE23_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE23_MODE_CFG_WIDTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE23_MODE_CFG_WIDTH,
           PB_PTLSCOM10_PSAVE23_MODE_CFG_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE23_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PSAVE23_MODE_CFG_WIDTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011816));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PSAVE23_MODE_CFG_WIDTH,
           PB_PTLSCOM10_PSAVE23_MODE_CFG_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE23_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE23_MODE_CFG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE23_MODE_CFG_SPARE,
           PB_PTLSCOM10_PSAVE23_MODE_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE23_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE23_MODE_CFG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE23_MODE_CFG_SPARE,
           PB_PTLSCOM10_PSAVE23_MODE_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE23_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PSAVE23_MODE_CFG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011816));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PSAVE23_MODE_CFG_SPARE,
           PB_PTLSCOM10_PSAVE23_MODE_CFG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE23_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE23_MODE_CFG_MIN_RAND_UC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE23_MODE_CFG_MIN_RAND_UC,
           PB_PTLSCOM10_PSAVE23_MODE_CFG_MIN_RAND_UC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE23_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PSAVE23_MODE_CFG_MIN_RAND_UC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011816));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PSAVE23_MODE_CFG_MIN_RAND_UC,
           PB_PTLSCOM10_PSAVE23_MODE_CFG_MIN_RAND_UC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE23_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PSAVE23_MODE_CFG_MIN_RAND_UC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10011816));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PSAVE23_MODE_CFG_MIN_RAND_UC,
           PB_PTLSCOM10_PSAVE23_MODE_CFG_MIN_RAND_UC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PSAVE23_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_TL_LINK_SYN_01_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011812;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_TL_LINK_SYN_01_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10011812;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_TL_LINK_SYN_01_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_TL_LINK_SYN_01_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10011812));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_TL_LINK_SYN_01_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_DOB01_DIB01_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011828;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_DOB01_DIB01_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011828;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_DOB01_DIB01_INT_ERR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_DOB01_DIB01_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x11011828));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_DOB01_DIB01_INT_ERR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PMU1_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011822;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PMU1_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011822;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PMU1_CNPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PMU1_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x11011822));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PMU1_CNPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PTL_FIR_REG_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011800;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PTL_FIR_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x11011800;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PTL_FIR_REG_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PTL_FIR_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PTL_FIR_REG_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PTL_FIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PTL_FIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PTL_FIR_REG_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PTL_FIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PTL_FIR_REG_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PTL_FIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PTL_FIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PTL_FIR_REG_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PTL_FIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PTL_FIR_REG_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2, 0x1, 0x11011800));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_MAILBOX_30_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011836;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_MAILBOX_30_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011836;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_MAILBOX_30_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_MAILBOX_30_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x12011836));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_MAILBOX_30_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_MAILBOX_31_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011837;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_MAILBOX_31_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011837;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_MAILBOX_31_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_MAILBOX_31_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x12011837));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_MAILBOX_31_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PSAVE01_MISC_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011815;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PSAVE01_MISC_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011815;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PSAVE01_MISC_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PSAVE01_MISC_CFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PSAVE01_MISC_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUC,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUC,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUC,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUC,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUC,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUC,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUT,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUT,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUT,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUT,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUT,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUT,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_SPARE,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_SPARE,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_SPARE,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_HALF_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUC,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUC,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUC,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUC,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUC,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUC,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUT,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUT,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUT,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUT,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUT,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUT,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_SPARE,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_SPARE,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_SPARE,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_QTR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_WSIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_WSIZE,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_WSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_WSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PSAVE01_MISC_CFG_WSIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_WSIZE,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_WSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_WSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PSAVE01_MISC_CFG_WSIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x12011815));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PSAVE01_MISC_CFG_WSIZE,
           PB_PTLSCOM45_PSAVE01_MISC_CFG_WSIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PSAVE01_MISC_CFG_WSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3012410;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3012410;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3012410));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG_MONITOR_1_COUNTER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3012410));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG_MONITOR_1_COUNTER,
           PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG_MONITOR_1_COUNTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG_MONITOR_1_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG_MONITOR_1_COUNTER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3012410));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG_MONITOR_1_COUNTER,
           PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG_MONITOR_1_COUNTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG_MONITOR_1_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG_MONITOR_1_COUNTER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3012410));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG_MONITOR_1_COUNTER,
           PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG_MONITOR_1_COUNTER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_MONITOR_1_COUNTER_REG_MONITOR_1_COUNTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3011c89;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3011c89;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL0,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL0,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL0,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL1,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL1,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL1,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL2,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL2,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL2,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL3,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL3,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL3,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL4,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL4,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL4,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL5,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL5,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL5,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_RGRPSEL5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL0,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL0,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL0,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL1,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL1,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL1,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL2,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL2,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c89));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL2,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_FLEX_CGRPSEL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3011c81;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3011c81;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SCOPE,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SCOPE,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SCOPE,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SPARE67(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SPARE67,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SPARE67_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SPARE67 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SPARE67(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SPARE67,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SPARE67_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SPARE67 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SPARE67(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SPARE67,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SPARE67_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SPARE67 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_BASE,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_BASE,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_BASE,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c81));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3011c80;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3011c80;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_HTM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CONTENT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CONTENT_SEL,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CONTENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CONTENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CONTENT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CONTENT_SEL,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CONTENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CONTENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CONTENT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CONTENT_SEL,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CONTENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CONTENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CAPTURE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CAPTURE,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CAPTURE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CAPTURE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CAPTURE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CAPTURE,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CAPTURE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CAPTURE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CAPTURE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CAPTURE,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CAPTURE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_CAPTURE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SINGLE_TSTAMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_MARKERS_ONLY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_DIS_FORCE_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SYNC_STAMP_FORCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SYNC_STAMP_FORCE,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SYNC_STAMP_FORCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SYNC_STAMP_FORCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SYNC_STAMP_FORCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SYNC_STAMP_FORCE,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SYNC_STAMP_FORCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SYNC_STAMP_FORCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SYNC_STAMP_FORCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SYNC_STAMP_FORCE,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SYNC_STAMP_FORCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SYNC_STAMP_FORCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_WRITETOIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_VGTARGET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_VGTARGET,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_VGTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_VGTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_VGTARGET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_VGTARGET,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_VGTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_VGTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_VGTARGET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_VGTARGET,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_VGTARGET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_VGTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE4043(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE4043,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE4043_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE4043 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE4043(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE4043,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE4043_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE4043 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE4043(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011c80));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE4043,
           PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE4043_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM0_SC_HTM_MODE_SPARE4043 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_0_PFIRWOF_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010848;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_0_PFIRWOF_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010848;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_0_PFIRWOF_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_0_PFIRWOF_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8010848));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_0_PFIRWOF_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010880;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010880;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8010882, 0x8010881, 0x8010880));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010881;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010881;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8010882, 0x8010881, 0x8010880));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010882;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010882;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8010882, 0x8010881, 0x8010880));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_PFIRPFIR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010882, 0x8010881, 0x8010880));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_PFIRPFIR,
           PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_PFIRPFIR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_PFIRPFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_PFIRPFIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010882, 0x8010881, 0x8010880));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_PFIRPFIR,
           PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_PFIRPFIR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_PFIRPFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_PFIRPFIR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010882, 0x8010881, 0x8010880));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_PFIRPFIR,
           PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_PFIRPFIR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PFIR_REG_PFIRPFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011803;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011803;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011803));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011803));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011803));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011803));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011803));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011803));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011803));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


}
}

#endif
