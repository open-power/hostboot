/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mc/reg00012.H $           */
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

#ifndef __MC_REG00012_H_
#define __MC_REG00012_H_

namespace scomt
{
namespace mc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL2_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL2_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL2_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL2_RW;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL2_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL2_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL2_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL2_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL2_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL2_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL2_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL2_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL2_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL2_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL2_WO_OR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL2_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL2_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL2_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_0_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_0_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_0_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_0_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_0_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_0_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_0_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_0_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_0_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_0_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL2_0_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_0_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_1_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_1_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_1_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_1_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_1_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_1_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_1_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_1_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_1_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_1_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL2_1_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_1_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_2_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_2_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_2_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_2_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_2_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_2_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_2_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_2_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_2_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_2_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL2_2_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_2_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_3_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_3_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_3_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_3_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_3_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_3_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_3_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_3_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_3_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_3_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL2_3_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_3_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_4_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_4_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_4_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_4_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_4_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_4_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_4_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_4_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_4_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_4_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL2_4_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_4_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_5_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_5_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_5_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_5_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_5_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_5_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_5_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_5_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_5_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_5_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL2_5_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_5_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_6_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_6_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_6_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_6_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_6_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_6_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_6_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_6_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_6_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_6_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL2_6_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_6_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_7_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_7_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_7_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_7_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_7_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_7_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_7_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_7_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_7_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_7_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL2_7_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_7_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_8_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_8_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_8_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_8_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_8_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_8_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_8_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_8_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_8_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_8_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL2_8_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_8_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_9_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_9_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_9_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_9_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_9_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_9_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_9_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_9_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_9_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_9_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL2_9_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_9_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_10_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_10_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_10_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_10_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_10_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_10_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_10_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_10_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_10_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_10_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL2_10_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_10_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_11_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_11_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_11_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_11_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_11_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_11_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_11_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_11_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_11_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_11_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL2_11_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_11_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_12_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_12_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_12_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_12_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_12_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_12_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_12_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_12_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_12_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_12_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL2_12_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_12_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_13_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_13_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_13_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_13_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_13_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_13_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_13_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_13_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_13_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_13_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL2_13_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_13_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_14_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_14_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_14_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_14_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_14_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_14_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_14_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_14_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_14_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_14_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL2_14_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_14_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_MASK0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_MASK0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_MASK0(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_MASK0;
#endif
    return fapi2::getScom(i_target, CPLT_MASK0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_MASK0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_MASK0));
#endif
    return fapi2::putScom(i_target, CPLT_MASK0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPLT_MASK0_ITR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_MASK0));
#endif
    return o_data.insertFromRight<CPLT_MASK0_ITR_MASK,
           CPLT_MASK0_ITR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_MASK0_ITR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_MASK0));
#endif
    return o_data.insertFromRight<CPLT_MASK0_ITR_MASK,
           CPLT_MASK0_ITR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_MASK0_ITR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_MASK0));
#endif
    return i_data.extractToRight<CPLT_MASK0_ITR_MASK,
           CPLT_MASK0_ITR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTRL_PROTECT_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTRL_PROTECT_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTRL_PROTECT_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTRL_PROTECT_MODE_REG;
#endif
    return fapi2::getScom(i_target, CTRL_PROTECT_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTRL_PROTECT_MODE_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTRL_PROTECT_MODE_REG));
#endif
    return fapi2::putScom(i_target, CTRL_PROTECT_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_PROTECT_MODE_REG));
#endif
    return o_data.insertFromRight<CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_PROTECT_MODE_REG));
#endif
    return o_data.insertFromRight<CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_PROTECT_MODE_REG));
#endif
    return o_data.setBit<CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_PROTECT_MODE_REG));
#endif
    return o_data.clearBit<CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_PROTECT_MODE_REG));
#endif
    return i_data.extractToRight<CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_PROTECT_MODE_REG));
#endif
    return i_data.getBit<CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_PROTECT_MODE_REG));
#endif
    return o_data.insertFromRight<CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_PROTECT_MODE_REG));
#endif
    return o_data.insertFromRight<CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_PROTECT_MODE_REG));
#endif
    return o_data.setBit<CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_PROTECT_MODE_REG));
#endif
    return o_data.clearBit<CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_PROTECT_MODE_REG));
#endif
    return i_data.extractToRight<CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_PROTECT_MODE_REG));
#endif
    return i_data.getBit<CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_DBG_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_DBG_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_DBG_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_DBG_MODE_REG;
#endif
    return fapi2::getScom(i_target, EPS_DBG_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_DBG_MODE_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return fapi2::putScom(i_target, EPS_DBG_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_GLB_BRCST_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_GLB_BRCST_MODE,
           EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_GLB_BRCST_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_GLB_BRCST_MODE,
           EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_GLB_BRCST_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_GLB_BRCST_MODE,
           EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_TRACE_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_TRACE_SEL_MODE,
           EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_TRACE_SEL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_TRACE_SEL_MODE,
           EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_TRACE_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_TRACE_SEL_MODE,
           EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_TRIG_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_TRIG_SEL_MODE,
           EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_TRIG_SEL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_TRIG_SEL_MODE,
           EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_TRIG_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_TRIG_SEL_MODE,
           EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_FREEZE_SEL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_FREEZE_SEL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<EPS_DBG_MODE_REG_FREEZE_SEL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<EPS_DBG_MODE_REG_FREEZE_SEL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_FREEZE_SEL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<EPS_DBG_MODE_REG_FREEZE_SEL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_TRACE_RUN_STATUS,
           EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_TRACE_RUN_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_TRACE_RUN_STATUS,
           EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_TRACE_RUN_STATUS,
           EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_IS_FROZEN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_IS_FROZEN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<EPS_DBG_MODE_REG_IS_FROZEN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<EPS_DBG_MODE_REG_IS_FROZEN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_IS_FROZEN_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<EPS_DBG_MODE_REG_IS_FROZEN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS,
           EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS,
           EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS,
           EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS,
           EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS,
           EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS,
           EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_FIR_GXSTOP4_MASK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_GXSTOP4_MASK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_FIR_GXSTOP4_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_GXSTOP4_MASK_REG;
#endif
    return fapi2::getScom(i_target, EPS_FIR_GXSTOP4_MASK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_FIR_GXSTOP4_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return fapi2::putScom(i_target, EPS_FIR_GXSTOP4_MASK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_OOB1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_OOB1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_OOB1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_OOB1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_OOB1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_OOB1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_OOB1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_OOB1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_OOB1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.insertFromRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.setBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return o_data.clearBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.extractToRight<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_GXSTOP4_MASK_REG));
#endif
    return i_data.getBit<EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_PSC_WRITE_PROTECT_ENABLE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_PSC_WRITE_PROTECT_ENABLE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_PSC_WRITE_PROTECT_ENABLE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_PSC_WRITE_PROTECT_ENABLE_REG;
#endif
    return fapi2::getScom(i_target, EPS_PSC_WRITE_PROTECT_ENABLE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_PSC_WRITE_PROTECT_ENABLE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return fapi2::putScom(i_target, EPS_PSC_WRITE_PROTECT_ENABLE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.setBit<EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.clearBit<EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return i_data.getBit<EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.setBit<EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.clearBit<EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return i_data.extractToRight<EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_WRITE_PROTECT_ENABLE_REG));
#endif
    return i_data.getBit<EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MBA_SCOMFIR_DBG1_SCOM0Q(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MBA_SCOMFIR_DBG1_SCOM0Q;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MBA_SCOMFIR_DBG1_SCOM0Q(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MBA_SCOMFIR_DBG1_SCOM0Q;
#endif
    return fapi2::getScom(i_target, MBA_SCOMFIR_DBG1_SCOM0Q, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MBA_SCOMFIR_DBG1_SCOM0Q(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_DBG1_SCOM0Q));
#endif
    return fapi2::putScom(i_target, MBA_SCOMFIR_DBG1_SCOM0Q, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_DBG1_SCOM0Q));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63,
           MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_DBG1_SCOM0Q));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63,
           MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_DBG1_SCOM0Q));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63,
           MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MBA_SCOMFIR_MCWATDATA8(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MBA_SCOMFIR_MCWATDATA8;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MBA_SCOMFIR_MCWATDATA8(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MBA_SCOMFIR_MCWATDATA8;
#endif
    return fapi2::getScom(i_target, MBA_SCOMFIR_MCWATDATA8, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MBA_SCOMFIR_MCWATDATA8(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATDATA8));
#endif
    return fapi2::putScom(i_target, MBA_SCOMFIR_MCWATDATA8, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATDATA8_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATDATA8));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATDATA8_PATTERN_B,
           MBA_SCOMFIR_MCWATDATA8_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATDATA8_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATDATA8_PATTERN_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATDATA8));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATDATA8_PATTERN_B,
           MBA_SCOMFIR_MCWATDATA8_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATDATA8_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATDATA8_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATDATA8));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATDATA8_PATTERN_B,
           MBA_SCOMFIR_MCWATDATA8_PATTERN_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATDATA8_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATDATA8_MASK_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATDATA8));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATDATA8_MASK_B,
           MBA_SCOMFIR_MCWATDATA8_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATDATA8_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATDATA8_MASK_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATDATA8));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATDATA8_MASK_B,
           MBA_SCOMFIR_MCWATDATA8_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATDATA8_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATDATA8_MASK_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATDATA8));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATDATA8_MASK_B,
           MBA_SCOMFIR_MCWATDATA8_MASK_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATDATA8_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MBA_SCOMFIR_WATCFG0AQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MBA_SCOMFIR_WATCFG0AQ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MBA_SCOMFIR_WATCFG0AQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MBA_SCOMFIR_WATCFG0AQ;
#endif
    return fapi2::getScom(i_target, MBA_SCOMFIR_WATCFG0AQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MBA_SCOMFIR_WATCFG0AQ(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_WATCFG0AQ));
#endif
    return fapi2::putScom(i_target, MBA_SCOMFIR_WATCFG0AQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_WATCFG0AQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL,
           MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_WATCFG0AQ));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL,
           MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_WATCFG0AQ));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL,
           MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MULTICAST_GROUP_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MULTICAST_GROUP_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MULTICAST_GROUP_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MULTICAST_GROUP_4;
#endif
    return fapi2::getScom(i_target, MULTICAST_GROUP_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MULTICAST_GROUP_4(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MULTICAST_GROUP_4));
#endif
    return fapi2::putScom(i_target, MULTICAST_GROUP_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MULTICAST_GROUP_4_MULTICAST4_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MULTICAST_GROUP_4));
#endif
    return o_data.insertFromRight<MULTICAST_GROUP_4_MULTICAST4_GROUP,
           MULTICAST_GROUP_4_MULTICAST4_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MULTICAST_GROUP_4_MULTICAST4_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MULTICAST_GROUP_4_MULTICAST4_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MULTICAST_GROUP_4));
#endif
    return o_data.insertFromRight<MULTICAST_GROUP_4_MULTICAST4_GROUP,
           MULTICAST_GROUP_4_MULTICAST4_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MULTICAST_GROUP_4_MULTICAST4_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MULTICAST_GROUP_4_MULTICAST4_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MULTICAST_GROUP_4));
#endif
    return i_data.extractToRight<MULTICAST_GROUP_4_MULTICAST4_GROUP,
           MULTICAST_GROUP_4_MULTICAST4_GROUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MULTICAST_GROUP_4_MULTICAST4_GROUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PCB_OPCG_STOP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PCB_OPCG_STOP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PCB_OPCG_STOP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PCB_OPCG_STOP;
#endif
    return fapi2::getScom(i_target, PCB_OPCG_STOP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PCB_OPCG_STOP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PCB_OPCG_STOP));
#endif
    return fapi2::putScom(i_target, PCB_OPCG_STOP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PCB_OPCG_STOP_PCB_OPCGSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PCB_OPCG_STOP));
#endif
    return o_data.insertFromRight<PCB_OPCG_STOP_PCB_OPCGSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PCB_OPCG_STOP_PCB_OPCGSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PCB_OPCG_STOP));
#endif
    return o_data.insertFromRight<PCB_OPCG_STOP_PCB_OPCGSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PCB_OPCG_STOP_PCB_OPCGSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PCB_OPCG_STOP));
#endif
    return o_data.setBit<PCB_OPCG_STOP_PCB_OPCGSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PCB_OPCG_STOP_PCB_OPCGSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PCB_OPCG_STOP));
#endif
    return o_data.clearBit<PCB_OPCG_STOP_PCB_OPCGSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PCB_OPCG_STOP_PCB_OPCGSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PCB_OPCG_STOP));
#endif
    return i_data.extractToRight<PCB_OPCG_STOP_PCB_OPCGSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PCB_OPCG_STOP_PCB_OPCGSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PCB_OPCG_STOP));
#endif
    return i_data.getBit<PCB_OPCG_STOP_PCB_OPCGSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PRE_COUNTER_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PRE_COUNTER_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PRE_COUNTER_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PRE_COUNTER_REG;
#endif
    return fapi2::getScom(i_target, PRE_COUNTER_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PRE_COUNTER_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PRE_COUNTER_REG));
#endif
    return fapi2::putScom(i_target, PRE_COUNTER_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PRE_COUNTER_REG_PRE_COUNTER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PRE_COUNTER_REG));
#endif
    return o_data.insertFromRight<PRE_COUNTER_REG_PRE_COUNTER,
           PRE_COUNTER_REG_PRE_COUNTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PRE_COUNTER_REG_PRE_COUNTER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PRE_COUNTER_REG_PRE_COUNTER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PRE_COUNTER_REG));
#endif
    return o_data.insertFromRight<PRE_COUNTER_REG_PRE_COUNTER,
           PRE_COUNTER_REG_PRE_COUNTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PRE_COUNTER_REG_PRE_COUNTER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PRE_COUNTER_REG_PRE_COUNTER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PRE_COUNTER_REG));
#endif
    return i_data.extractToRight<PRE_COUNTER_REG_PRE_COUNTER,
           PRE_COUNTER_REG_PRE_COUNTER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PRE_COUNTER_REG_PRE_COUNTER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCFIRACT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIRACT0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCFIRACT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIRACT0;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCFIRACT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCFIRACT0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIRACT0));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCFIRACT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIRACT0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0,
           SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIRACT0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0,
           SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIRACT0));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0,
           SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCMODE0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCMODE0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCMODE0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCMODE0;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCMODE0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCMODE0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCMODE0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_RESERVED_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_RESERVED_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_RESERVED_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_RESERVED_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_RESERVED_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_RESERVED_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_RESERVED_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_RESERVED_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_RESERVED_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_RESERVED_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_DISABLE_MC_SYNC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_DISABLE_MC_SYNC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_DISABLE_MC_SYNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_DISABLE_MC_SYNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_DISABLE_MC_SYNC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_DISABLE_MC_SYNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_RESERVED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_RESERVED_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_RESERVED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_RESERVED_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_RESERVED_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_RESERVED_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_RESERVED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_64B_WR_IS_PWRT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_64B_WR_IS_PWRT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_64B_WR_IS_PWRT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_64B_WR_IS_PWRT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_64B_WR_IS_PWRT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_64B_WR_IS_PWRT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE,
           SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE,
           SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE,
           SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_CL_FINE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_CL_FINE_DISABLE,
           SCOMFIR_MCMODE0_CL_FINE_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_CL_FINE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_CL_FINE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_CL_FINE_DISABLE,
           SCOMFIR_MCMODE0_CL_FINE_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_CL_FINE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_CL_FINE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_CL_FINE_DISABLE,
           SCOMFIR_MCMODE0_CL_FINE_DISABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_CL_FINE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY,
           SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY,
           SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY,
           SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_MEM_MAP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_MEM_MAP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_MEM_MAP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_MEM_MAP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_MEM_MAP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_MEM_MAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_MEM_MAP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_MEM_MAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_MEM_MAP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_MEM_MAP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_MEM_MAP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_MEM_MAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ADD_HASH_BITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ADD_HASH_BITS,
           SCOMFIR_MCMODE0_ADD_HASH_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ADD_HASH_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ADD_HASH_BITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ADD_HASH_BITS,
           SCOMFIR_MCMODE0_ADD_HASH_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ADD_HASH_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_ADD_HASH_BITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_ADD_HASH_BITS,
           SCOMFIR_MCMODE0_ADD_HASH_BITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ADD_HASH_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_ADD_HASH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_ADD_HASH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_ENABLE_ADD_HASH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_ENABLE_ADD_HASH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_ENABLE_ADD_HASH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_ENABLE_ADD_HASH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_41_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_41_63,
           SCOMFIR_MCMODE0_RESERVED_41_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_41_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_41_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_41_63,
           SCOMFIR_MCMODE0_RESERVED_41_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_41_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_RESERVED_41_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_RESERVED_41_63,
           SCOMFIR_MCMODE0_RESERVED_41_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE0_RESERVED_41_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCPERF1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCPERF1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCPERF1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCPERF1;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCPERF1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCPERF1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCPERF1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_FASTPATH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DISABLE_FASTPATH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_FASTPATH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DISABLE_FASTPATH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_FASTPATH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_DISABLE_FASTPATH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_DISABLE_FASTPATH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_DISABLE_FASTPATH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCPERF1_DISABLE_FASTPATH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK,
           SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK,
           SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK,
           SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH,
           SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH,
           SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH,
           SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT,
           SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT,
           SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT,
           SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH,
           SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH,
           SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH,
           SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE,
           SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE,
           SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE,
           SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE,
           SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE,
           SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE,
           SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE,
           SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE,
           SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE,
           SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_NONSPEC_EDATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_EN_NONSPEC_EDATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_NONSPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_NONSPEC_EDATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_EN_NONSPEC_EDATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_NONSPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_NONSPEC_EDATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_EN_NONSPEC_EDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_NONSPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_EN_NONSPEC_EDATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_EN_NONSPEC_EDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_NONSPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_EN_NONSPEC_EDATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_EN_NONSPEC_EDATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_NONSPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCPERF1_EN_NONSPEC_EDATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_EN_NONSPEC_EDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_NONSPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_SPEC_EDATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_EN_SPEC_EDATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_SPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_SPEC_EDATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_EN_SPEC_EDATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_SPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_SPEC_EDATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_EN_SPEC_EDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_SPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_EN_SPEC_EDATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_EN_SPEC_EDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_SPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_EN_SPEC_EDATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_EN_SPEC_EDATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_SPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCPERF1_EN_SPEC_EDATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_EN_SPEC_EDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_SPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_VG_SPECDIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_EN_VG_SPECDIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_VG_SPECDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_VG_SPECDIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_EN_VG_SPECDIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_VG_SPECDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_VG_SPECDIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_EN_VG_SPECDIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_VG_SPECDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_EN_VG_SPECDIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_EN_VG_SPECDIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_VG_SPECDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_EN_VG_SPECDIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_EN_VG_SPECDIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_VG_SPECDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCPERF1_EN_VG_SPECDIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_EN_VG_SPECDIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_EN_VG_SPECDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_RESERVED_47_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_RESERVED_47_63,
           SCOMFIR_MCPERF1_RESERVED_47_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_RESERVED_47_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_RESERVED_47_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_RESERVED_47_63,
           SCOMFIR_MCPERF1_RESERVED_47_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_RESERVED_47_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_RESERVED_47_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_RESERVED_47_63,
           SCOMFIR_MCPERF1_RESERVED_47_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCPERF1_RESERVED_47_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCWATACT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCWATACT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCWATACT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCWATACT;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCWATACT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCWATACT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCWATACT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.setBit<SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.clearBit<SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.getBit<SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_RESERVED_36_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_RESERVED_36_47,
           SCOMFIR_MCWATACT_RESERVED_36_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_RESERVED_36_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCWATACT_RESERVED_36_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return o_data.insertFromRight<SCOMFIR_MCWATACT_RESERVED_36_47,
           SCOMFIR_MCWATACT_RESERVED_36_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_RESERVED_36_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCWATACT_RESERVED_36_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCWATACT));
#endif
    return i_data.extractToRight<SCOMFIR_MCWATACT_RESERVED_36_47,
           SCOMFIR_MCWATACT_RESERVED_36_47_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCWATACT_RESERVED_36_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA1_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA1_TR0_CONFIG_9;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA1_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA1_TR0_CONFIG_9;
#endif
    return fapi2::getScom(i_target, TRA1_TR0_CONFIG_9, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA1_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return fapi2::putScom(i_target, TRA1_TR0_CONFIG_9, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_MATCHA_MUXSEL,
           TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_MATCHA_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_MATCHA_MUXSEL,
           TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_MATCHA_MUXSEL,
           TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_MATCHB_MUXSEL,
           TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_MATCHB_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_MATCHB_MUXSEL,
           TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_MATCHB_MUXSEL,
           TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_MATCHC_MUXSEL,
           TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_MATCHC_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_MATCHC_MUXSEL,
           TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_MATCHC_MUXSEL,
           TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_MATCHD_MUXSEL,
           TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_MATCHD_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_MATCHD_MUXSEL,
           TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_MATCHD_MUXSEL,
           TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_TRIG0_OR_MASK,
           TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG0_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_TRIG0_OR_MASK,
           TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_TRIG0_OR_MASK,
           TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_TRIG0_AND_MASK,
           TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG0_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_TRIG0_AND_MASK,
           TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_TRIG0_AND_MASK,
           TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_TRIG1_OR_MASK,
           TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG1_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_TRIG1_OR_MASK,
           TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_TRIG1_OR_MASK,
           TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_TRIG1_AND_MASK,
           TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG1_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_TRIG1_AND_MASK,
           TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_TRIG1_AND_MASK,
           TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_MATCH_NOT_MODE,
           TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_MATCH_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_MATCH_NOT_MODE,
           TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_MATCH_NOT_MODE,
           TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_ERROR_CMP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA1_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA1_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA1_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA1_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA1_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_INTERRUPT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_INTERRUPT_REG;
#endif
    return fapi2::getScom(i_target, XSTOP_INTERRUPT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP_INTERRUPT_REG));
#endif
    return fapi2::putScom(i_target, XSTOP_INTERRUPT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}



}
}

#endif
