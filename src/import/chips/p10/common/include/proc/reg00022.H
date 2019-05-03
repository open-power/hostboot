/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00022.H $         */
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

#ifndef __PROC_REG00022_H_
#define __PROC_REG00022_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CONF0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CONF0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF0_RW;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CONF0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CONF0_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CONF0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CONF0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF0_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CONF0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF0_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CONF0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CONF0_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF0_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CONF0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF0_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CONF0_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CONF0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CONF0_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC,
           TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC,
           TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC,
           TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_6G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_6G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_6G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_6G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_6G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_6G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_RESERVED_6G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_6G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_6G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_6G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_6G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_6G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_7G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_7G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_7G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_7G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_7G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_7G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_RESERVED_7G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_7G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_7G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_7G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_7G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_7G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC,
           TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC,
           TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC,
           TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_14G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_14G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_14G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_14G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_14G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_14G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_RESERVED_14G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_14G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_14G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_14G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_14G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_14G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_15G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_15G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_15G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_15G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_15G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_15G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_RESERVED_15G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_15G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_15G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_15G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_15G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_15G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC,
           TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC,
           TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC,
           TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_22G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_22G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_22G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_22G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_22G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_22G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_RESERVED_22G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_22G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_22G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_22G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_22G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_22G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_23G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_23G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_23G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_23G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_23G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_23G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_RESERVED_23G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_23G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_23G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_23G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_23G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_23G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC,
           TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC,
           TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC,
           TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_30G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_30G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_30G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_30G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_30G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_30G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_RESERVED_30G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_30G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_30G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_30G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_30G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_30G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_31G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_31G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_31G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_31G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_31G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_31G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_RESERVED_31G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_31G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_31G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_31G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_31G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_31G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_42G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_42G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_42G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_42G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_42G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_42G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_RESERVED_42G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_42G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_42G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_42G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_42G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_42G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_43G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_43G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_43G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_43G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_43G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_43G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_RESERVED_43G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_43G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_43G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_43G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_43G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_43G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_45G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_45G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_45G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_45G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_45G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_45G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_RESERVED_45G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_45G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_45G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_RESERVED_45G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_45G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_45G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_45G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_RESERVED_45G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_45G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_RESERVED_45G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_RESERVED_45G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_RESERVED_45G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_47G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_48G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_49G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_50G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_ID_DC_51G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_TC_TOPOLOGY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF0_RW, TP_TCN1_N1_CPLT_CONF0_WO_CLEAR, TP_TCN1_N1_CPLT_CONF0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL0_RW;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CTRL0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CTRL0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CTRL0_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL0_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CTRL0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL0_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CTRL0_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CTRL0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CTRL0_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC,
           TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC,
           TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC,
           TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC,
           TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC,
           TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC,
           TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_EPS_FIR_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_FIR_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_EPS_FIR_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_FIR_MODE_REG;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_EPS_FIR_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_EPS_FIR_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_EPS_FIR_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_OPCG_ALIGN(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_OPCG_ALIGN;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_OPCG_ALIGN(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_OPCG_ALIGN;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_OPCG_ALIGN, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_OPCG_ALIGN(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_OPCG_ALIGN, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.setBit<TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.clearBit<TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.getBit<TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.setBit<TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.clearBit<TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.getBit<TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.setBit<TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.clearBit<TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.getBit<TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.setBit<TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.clearBit<TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.getBit<TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT,
           TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT,
           TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT,
           TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO,
           TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO,
           TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO,
           TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES,
           TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES,
           TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES,
           TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_PHASE_COUNTER_RESET(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_PHASE_COUNTER_RESET;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_PHASE_COUNTER_RESET(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_PHASE_COUNTER_RESET;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_PHASE_COUNTER_RESET, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_PHASE_COUNTER_RESET(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_PHASE_COUNTER_RESET));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_PHASE_COUNTER_RESET, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_PHASE_COUNTER_RESET));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_PHASE_COUNTER_RESET));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_PHASE_COUNTER_RESET));
#endif
    return o_data.setBit<TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_PHASE_COUNTER_RESET));
#endif
    return o_data.clearBit<TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_PHASE_COUNTER_RESET));
#endif
    return i_data.extractToRight<TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_PHASE_COUNTER_RESET));
#endif
    return i_data.getBit<TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA0_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA0_TR1_CONFIG_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA0_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA0_TR1_CONFIG_4;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA0_TR1_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA0_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_4));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA0_TR1_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA0_TR1_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA0_TR1_CONFIG_4_A,
           TP_TCN1_N1_TRA0_TR1_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA0_TR1_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA0_TR1_CONFIG_4_A,
           TP_TCN1_N1_TRA0_TR1_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA0_TR1_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_4));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA0_TR1_CONFIG_4_A,
           TP_TCN1_N1_TRA0_TR1_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA0_TR1_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA0_TR1_CONFIG_4_B,
           TP_TCN1_N1_TRA0_TR1_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA0_TR1_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA0_TR1_CONFIG_4_B,
           TP_TCN1_N1_TRA0_TR1_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA0_TR1_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_4));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA0_TR1_CONFIG_4_B,
           TP_TCN1_N1_TRA0_TR1_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA1_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA1_TR0_CONFIG_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA1_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA1_TR0_CONFIG_2;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA1_TR0_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA1_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_2));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA1_TR0_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR0_CONFIG_2_A,
           TP_TCN1_N1_TRA1_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR0_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR0_CONFIG_2_A,
           TP_TCN1_N1_TRA1_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA1_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA1_TR0_CONFIG_2_A,
           TP_TCN1_N1_TRA1_TR0_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR0_CONFIG_2_B,
           TP_TCN1_N1_TRA1_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR0_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR0_CONFIG_2_B,
           TP_TCN1_N1_TRA1_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA1_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA1_TR0_CONFIG_2_B,
           TP_TCN1_N1_TRA1_TR0_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA2_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA2_TR0_CONFIG_5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA2_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA2_TR0_CONFIG_5;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA2_TR0_CONFIG_5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA2_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_5));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA2_TR0_CONFIG_5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA2_TR0_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA2_TR0_CONFIG_5_C,
           TP_TCN1_N1_TRA2_TR0_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA2_TR0_CONFIG_5_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA2_TR0_CONFIG_5_C,
           TP_TCN1_N1_TRA2_TR0_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA2_TR0_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_5));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA2_TR0_CONFIG_5_C,
           TP_TCN1_N1_TRA2_TR0_CONFIG_5_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA2_TR0_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA2_TR0_CONFIG_5_D,
           TP_TCN1_N1_TRA2_TR0_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA2_TR0_CONFIG_5_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA2_TR0_CONFIG_5_D,
           TP_TCN1_N1_TRA2_TR0_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA2_TR0_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_5));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA2_TR0_CONFIG_5_D,
           TP_TCN1_N1_TRA2_TR0_CONFIG_5_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA3_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA3_TR1_CONFIG_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA3_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA3_TR1_CONFIG_3;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA3_TR1_CONFIG_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA3_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_3));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA3_TR1_CONFIG_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA3_TR1_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA3_TR1_CONFIG_3_C,
           TP_TCN1_N1_TRA3_TR1_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA3_TR1_CONFIG_3_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA3_TR1_CONFIG_3_C,
           TP_TCN1_N1_TRA3_TR1_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA3_TR1_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_3));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA3_TR1_CONFIG_3_C,
           TP_TCN1_N1_TRA3_TR1_CONFIG_3_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA3_TR1_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA3_TR1_CONFIG_3_D,
           TP_TCN1_N1_TRA3_TR1_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA3_TR1_CONFIG_3_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA3_TR1_CONFIG_3_D,
           TP_TCN1_N1_TRA3_TR1_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA3_TR1_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_3));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA3_TR1_CONFIG_3_D,
           TP_TCN1_N1_TRA3_TR1_CONFIG_3_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA4_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA4_TR1_CONFIG_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA4_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA4_TR1_CONFIG_2;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA4_TR1_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA4_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_2));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA4_TR1_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA4_TR1_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA4_TR1_CONFIG_2_A,
           TP_TCN1_N1_TRA4_TR1_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA4_TR1_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA4_TR1_CONFIG_2_A,
           TP_TCN1_N1_TRA4_TR1_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA4_TR1_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_2));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA4_TR1_CONFIG_2_A,
           TP_TCN1_N1_TRA4_TR1_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA4_TR1_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA4_TR1_CONFIG_2_B,
           TP_TCN1_N1_TRA4_TR1_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA4_TR1_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA4_TR1_CONFIG_2_B,
           TP_TCN1_N1_TRA4_TR1_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA4_TR1_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_2));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA4_TR1_CONFIG_2_B,
           TP_TCN1_N1_TRA4_TR1_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA5_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA5_TR0_CONFIG_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA5_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA5_TR0_CONFIG_4;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA5_TR0_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA5_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_4));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA5_TR0_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA5_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA5_TR0_CONFIG_4_A,
           TP_TCN1_N1_TRA5_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA5_TR0_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA5_TR0_CONFIG_4_A,
           TP_TCN1_N1_TRA5_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA5_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA5_TR0_CONFIG_4_A,
           TP_TCN1_N1_TRA5_TR0_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA5_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA5_TR0_CONFIG_4_B,
           TP_TCN1_N1_TRA5_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA5_TR0_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA5_TR0_CONFIG_4_B,
           TP_TCN1_N1_TRA5_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA5_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA5_TR0_CONFIG_4_B,
           TP_TCN1_N1_TRA5_TR0_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA6_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA6_TR0_CONFIG_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA6_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA6_TR0_CONFIG_3;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA6_TR0_CONFIG_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA6_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_3));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA6_TR0_CONFIG_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_CONFIG_3_C,
           TP_TCN1_N1_TRA6_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_CONFIG_3_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_CONFIG_3_C,
           TP_TCN1_N1_TRA6_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_CONFIG_3_C,
           TP_TCN1_N1_TRA6_TR0_CONFIG_3_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_CONFIG_3_D,
           TP_TCN1_N1_TRA6_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_CONFIG_3_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_CONFIG_3_D,
           TP_TCN1_N1_TRA6_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_CONFIG_3_D,
           TP_TCN1_N1_TRA6_TR0_CONFIG_3_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_TOD_DATA_RCV_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_TOD_DATA_RCV_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_TOD_DATA_RCV_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_TOD_DATA_RCV_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_TOD_DATA_RCV_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_TOD_DATA_RCV_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOD_DATA_RCV_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_TOD_DATA_RCV_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOD_DATA_RCV_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV,
           TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOD_DATA_RCV_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV,
           TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOD_DATA_RCV_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV,
           TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_BCDE_CTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_CTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_BCDE_CTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_CTL;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCDE_CTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_BCDE_CTL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCDE_CTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_CTL_OP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_CTL_OP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_BCDE_CTL_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_BCDE_CTL_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_CTL_OP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_BCDE_CTL_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_CTL_ART,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_CTL_ART,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_BCDE_CTL_ART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_BCDE_CTL_ART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_CTL_ART,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_BCDE_CTL_ART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBABAR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABAR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBABAR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABAR0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBABAR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBABAR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBABAR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR0_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR0_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR0_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR0_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR0_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_VTARGET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR0_VTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_VTARGET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR0_VTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR0_VTARGET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR0_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR0_VTARGET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBABARMSK1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABARMSK1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBABARMSK1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABARMSK1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBABARMSK1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBABARMSK1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK1));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBABARMSK1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBARBUFVAL0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBARBUFVAL0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBARBUFVAL0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBARBUFVAL0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBARBUFVAL0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBARBUFVAL0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXISHBR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXISHBR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXISHBR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXISHBR1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXISHBR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXISHBR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHBR1));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXISHBR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHBR1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHBR1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHBR1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXISHCS0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXISHCS0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXISHCS0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXISHCS0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXISHCS0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXISHCS0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXISHCS0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXSHBR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHBR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXSHBR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHBR1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHBR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXSHBR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHBR1));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHBR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXSHCS0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHCS0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXSHCS0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHCS0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHCS0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXSHCS0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHCS0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CH_MISC_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CH_MISC_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_RX_CH_MISC_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_RX_CH_MISC_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_TX_TO_RT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_TX_TO_RT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_TX_TO_RT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_TX_TO_RT_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_TX_TO_RT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_TX_TO_RT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_TO_RT_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_TX_TO_RT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_TO_RT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE,
           TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_TO_RT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE,
           TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_TO_RT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE,
           TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_TO_RT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE,
           TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_TO_RT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE,
           TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_TO_RT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE,
           TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_NOTRUST_BAR0MASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_NOTRUST_BAR0MASK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_NOTRUST_BAR0MASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_NOTRUST_BAR0MASK;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_NOTRUST_BAR0MASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_NOTRUST_BAR0MASK(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR0MASK));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_NOTRUST_BAR0MASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR0MASK));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK,
           TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR0MASK));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK,
           TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR0MASK));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK,
           TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_NOTRUST_BAR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_NOTRUST_BAR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_NOTRUST_BAR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_NOTRUST_BAR1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_NOTRUST_BAR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_NOTRUST_BAR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR1));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_NOTRUST_BAR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR1));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1,
           TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR1));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1,
           TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR1));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1,
           TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_NOTRUST_BAR1MASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_NOTRUST_BAR1MASK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_NOTRUST_BAR1MASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_NOTRUST_BAR1MASK;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_NOTRUST_BAR1MASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_NOTRUST_BAR1MASK(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR1MASK));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_NOTRUST_BAR1MASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR1MASK));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK,
           TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR1MASK));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK,
           TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR1MASK));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK,
           TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP,
           TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP,
           TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP,
           TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP,
           TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP,
           TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP,
           TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_CLKIN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DCC_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PDLY_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_DIV_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX0_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_REFCLK_CLKMUX1_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_PLL_BNDY_BYPASS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_DPLL_TEST_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_DPLL_TEST_SEL,
           TP_TPCHIP_NET_PCBSLPERV_CTRL1_DPLL_TEST_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_DPLL_TEST_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_DPLL_TEST_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_DPLL_TEST_SEL,
           TP_TPCHIP_NET_PCBSLPERV_CTRL1_DPLL_TEST_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_DPLL_TEST_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_DPLL_TEST_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_DPLL_TEST_SEL,
           TP_TPCHIP_NET_PCBSLPERV_CTRL1_DPLL_TEST_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_DPLL_TEST_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_SB_STRENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_SB_STRENGTH,
           TP_TPCHIP_NET_PCBSLPERV_CTRL1_SB_STRENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_SB_STRENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_SB_STRENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_SB_STRENGTH,
           TP_TPCHIP_NET_PCBSLPERV_CTRL1_SB_STRENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_SB_STRENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_SB_STRENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_SB_STRENGTH,
           TP_TPCHIP_NET_PCBSLPERV_CTRL1_SB_STRENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_SB_STRENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ASYNC_OBS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CPM_CAL_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_SENSEADJ_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_MODE,
           TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_MODE,
           TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RWX_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_MODE,
           TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_CLK_PULSE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


}
}

#endif
