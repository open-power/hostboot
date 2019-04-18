/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00034.H $         */
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

#ifndef __IOHS_REG00034_H_
#define __IOHS_REG00034_H_

namespace scomt
{
namespace iohs
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_CPLT_CTRL2_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000002;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_CPLT_CTRL2_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000002;
#endif
    return fapi2::getScom(i_target, AXON_CPLT_CTRL2_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_CPLT_CTRL2_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return fapi2::putScom(i_target, AXON_CPLT_CTRL2_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_CPLT_CTRL2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000022;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_CPLT_CTRL2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000022;
#endif
    return fapi2::getScom(i_target, AXON_CPLT_CTRL2_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_CPLT_CTRL2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return fapi2::putScom(i_target, AXON_CPLT_CTRL2_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_CPLT_CTRL2_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000012;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_CPLT_CTRL2_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000012;
#endif
    return fapi2::getScom(i_target, AXON_CPLT_CTRL2_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_CPLT_CTRL2_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return fapi2::putScom(i_target, AXON_CPLT_CTRL2_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_0_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_0_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_0_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_0_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_0_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.setBit<AXON_CPLT_CTRL2_0_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL2_0_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL2_0_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL2_0_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL2_0_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL2_0_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.getBit<AXON_CPLT_CTRL2_0_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_1_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_1_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_1_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_1_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_1_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.setBit<AXON_CPLT_CTRL2_1_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL2_1_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL2_1_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL2_1_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL2_1_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL2_1_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.getBit<AXON_CPLT_CTRL2_1_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_2_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_2_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_2_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_2_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_2_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.setBit<AXON_CPLT_CTRL2_2_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL2_2_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL2_2_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL2_2_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL2_2_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL2_2_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.getBit<AXON_CPLT_CTRL2_2_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_3_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_3_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_3_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_3_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_3_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.setBit<AXON_CPLT_CTRL2_3_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL2_3_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL2_3_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL2_3_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL2_3_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL2_3_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.getBit<AXON_CPLT_CTRL2_3_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_4_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_4_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_4_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_4_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_4_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.setBit<AXON_CPLT_CTRL2_4_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL2_4_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL2_4_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL2_4_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL2_4_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL2_4_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.getBit<AXON_CPLT_CTRL2_4_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_5_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_5_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_5_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_5_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_5_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.setBit<AXON_CPLT_CTRL2_5_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL2_5_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL2_5_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL2_5_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL2_5_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL2_5_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.getBit<AXON_CPLT_CTRL2_5_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_6_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_6_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_6_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_6_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_6_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.setBit<AXON_CPLT_CTRL2_6_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL2_6_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL2_6_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL2_6_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL2_6_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL2_6_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.getBit<AXON_CPLT_CTRL2_6_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_7_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_7_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_7_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_7_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_7_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.setBit<AXON_CPLT_CTRL2_7_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL2_7_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL2_7_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL2_7_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL2_7_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL2_7_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.getBit<AXON_CPLT_CTRL2_7_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_8_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_8_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_8_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_8_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_8_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.setBit<AXON_CPLT_CTRL2_8_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL2_8_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL2_8_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL2_8_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL2_8_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL2_8_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.getBit<AXON_CPLT_CTRL2_8_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_9_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_9_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_9_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_9_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_9_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.setBit<AXON_CPLT_CTRL2_9_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL2_9_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL2_9_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL2_9_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL2_9_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL2_9_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.getBit<AXON_CPLT_CTRL2_9_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_10_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_10_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_10_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_10_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_10_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.setBit<AXON_CPLT_CTRL2_10_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL2_10_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL2_10_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL2_10_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL2_10_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL2_10_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.getBit<AXON_CPLT_CTRL2_10_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_11_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_11_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_11_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_11_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_11_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.setBit<AXON_CPLT_CTRL2_11_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL2_11_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL2_11_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL2_11_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL2_11_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL2_11_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.getBit<AXON_CPLT_CTRL2_11_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_12_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_12_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_12_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_12_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_12_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.setBit<AXON_CPLT_CTRL2_12_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL2_12_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL2_12_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL2_12_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL2_12_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL2_12_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.getBit<AXON_CPLT_CTRL2_12_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_13_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_13_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_13_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_13_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_13_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.setBit<AXON_CPLT_CTRL2_13_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL2_13_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL2_13_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL2_13_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL2_13_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL2_13_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.getBit<AXON_CPLT_CTRL2_13_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_14_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_14_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_14_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL2_14_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL2_14_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.setBit<AXON_CPLT_CTRL2_14_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL2_14_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL2_14_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL2_14_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL2_14_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL2_14_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000022, 0x18000012, 0x18000002));
#endif
    return i_data.getBit<AXON_CPLT_CTRL2_14_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_CPLT_MASK0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000101;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_CPLT_MASK0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000101;
#endif
    return fapi2::getScom(i_target, AXON_CPLT_MASK0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_CPLT_MASK0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18000101));
#endif
    return fapi2::putScom(i_target, AXON_CPLT_MASK0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_MASK0_ITR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000101));
#endif
    return o_data.insertFromRight<AXON_CPLT_MASK0_ITR_MASK,
           AXON_CPLT_MASK0_ITR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_MASK0_ITR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000101));
#endif
    return o_data.insertFromRight<AXON_CPLT_MASK0_ITR_MASK,
           AXON_CPLT_MASK0_ITR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_MASK0_ITR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000101));
#endif
    return i_data.extractToRight<AXON_CPLT_MASK0_ITR_MASK,
           AXON_CPLT_MASK0_ITR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_CTRL_PROTECT_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x180003fe;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_CTRL_PROTECT_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x180003fe;
#endif
    return fapi2::getScom(i_target, AXON_CTRL_PROTECT_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_CTRL_PROTECT_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x180003fe));
#endif
    return fapi2::putScom(i_target, AXON_CTRL_PROTECT_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180003fe));
#endif
    return o_data.insertFromRight<AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180003fe));
#endif
    return o_data.insertFromRight<AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180003fe));
#endif
    return o_data.setBit<AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180003fe));
#endif
    return o_data.clearBit<AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180003fe));
#endif
    return i_data.extractToRight<AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180003fe));
#endif
    return i_data.getBit<AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180003fe));
#endif
    return o_data.insertFromRight<AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180003fe));
#endif
    return o_data.insertFromRight<AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180003fe));
#endif
    return o_data.setBit<AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180003fe));
#endif
    return o_data.clearBit<AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180003fe));
#endif
    return i_data.extractToRight<AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180003fe));
#endif
    return i_data.getBit<AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_EPS_FIR_GXSTOP3_MASK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18040016;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_EPS_FIR_GXSTOP3_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18040016;
#endif
    return fapi2::getScom(i_target, AXON_EPS_FIR_GXSTOP3_MASK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_EPS_FIR_GXSTOP3_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return fapi2::putScom(i_target, AXON_EPS_FIR_GXSTOP3_MASK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.setBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return o_data.clearBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040016));
#endif
    return i_data.getBit<AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_EPS_FIR_LOCAL_MASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1804000d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_EPS_FIR_LOCAL_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1804000d;
#endif
    return fapi2::getScom(i_target, AXON_EPS_FIR_LOCAL_MASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_EPS_FIR_LOCAL_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return fapi2::putScom(i_target, AXON_EPS_FIR_LOCAL_MASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_EPS_FIR_LOCAL_MASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1804000e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_EPS_FIR_LOCAL_MASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1804000e;
#endif
    return fapi2::getScom(i_target, AXON_EPS_FIR_LOCAL_MASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_EPS_FIR_LOCAL_MASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return fapi2::putScom(i_target, AXON_EPS_FIR_LOCAL_MASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_EPS_FIR_LOCAL_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1804000f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_EPS_FIR_LOCAL_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1804000f;
#endif
    return fapi2::getScom(i_target, AXON_EPS_FIR_LOCAL_MASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_EPS_FIR_LOCAL_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return fapi2::putScom(i_target, AXON_EPS_FIR_LOCAL_MASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_LOCAL_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.setBit<AXON_EPS_FIR_LOCAL_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return o_data.clearBit<AXON_EPS_FIR_LOCAL_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_LOCAL_MASK_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000f, 0x1804000e, 0x1804000d));
#endif
    return i_data.getBit<AXON_EPS_FIR_LOCAL_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_EPS_THERM_WSUB_SKITTER_DATA1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1805001a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_EPS_THERM_WSUB_SKITTER_DATA1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1805001a;
#endif
    return fapi2::getScom(i_target, AXON_EPS_THERM_WSUB_SKITTER_DATA1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_EPS_THERM_WSUB_SKITTER_DATA1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1805001a));
#endif
    return fapi2::putScom(i_target, AXON_EPS_THERM_WSUB_SKITTER_DATA1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_LOCAL_FIR_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1804000a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_LOCAL_FIR_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1804000a;
#endif
    return fapi2::getScom(i_target, AXON_LOCAL_FIR_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_LOCAL_FIR_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return fapi2::putScom(i_target, AXON_LOCAL_FIR_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_LOCAL_FIR_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1804000b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_LOCAL_FIR_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1804000b;
#endif
    return fapi2::getScom(i_target, AXON_LOCAL_FIR_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_LOCAL_FIR_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return fapi2::putScom(i_target, AXON_LOCAL_FIR_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_LOCAL_FIR_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1804000c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_LOCAL_FIR_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1804000c;
#endif
    return fapi2::getScom(i_target, AXON_LOCAL_FIR_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_LOCAL_FIR_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return fapi2::putScom(i_target, AXON_LOCAL_FIR_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.insertFromRight<AXON_LOCAL_FIR_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_FIR_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.setBit<AXON_LOCAL_FIR_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_FIR_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return o_data.clearBit<AXON_LOCAL_FIR_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_FIR_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.extractToRight<AXON_LOCAL_FIR_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_FIR_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1804000c, 0x1804000b, 0x1804000a));
#endif
    return i_data.getBit<AXON_LOCAL_FIR_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_FIR_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
