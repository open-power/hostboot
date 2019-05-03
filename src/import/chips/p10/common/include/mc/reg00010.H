/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mc/reg00010.H $           */
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

#ifndef __MC_REG00010_H_
#define __MC_REG00010_H_

namespace scomt
{
namespace mc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CC_PROTECT_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CC_PROTECT_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CC_PROTECT_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CC_PROTECT_MODE_REG;
#endif
    return fapi2::getScom(i_target, CC_PROTECT_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CC_PROTECT_MODE_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CC_PROTECT_MODE_REG));
#endif
    return fapi2::putScom(i_target, CC_PROTECT_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CC_PROTECT_MODE_REG));
#endif
    return o_data.insertFromRight<CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CC_PROTECT_MODE_REG));
#endif
    return o_data.insertFromRight<CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CC_PROTECT_MODE_REG));
#endif
    return o_data.setBit<CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CC_PROTECT_MODE_REG));
#endif
    return o_data.clearBit<CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CC_PROTECT_MODE_REG));
#endif
    return i_data.extractToRight<CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CC_PROTECT_MODE_REG));
#endif
    return i_data.getBit<CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CC_PROTECT_MODE_REG));
#endif
    return o_data.insertFromRight<CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CC_PROTECT_MODE_REG));
#endif
    return o_data.insertFromRight<CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CC_PROTECT_MODE_REG));
#endif
    return o_data.setBit<CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CC_PROTECT_MODE_REG));
#endif
    return o_data.clearBit<CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CC_PROTECT_MODE_REG));
#endif
    return i_data.extractToRight<CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CC_PROTECT_MODE_REG));
#endif
    return i_data.getBit<CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLOCK_STAT_SL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLOCK_STAT_SL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLOCK_STAT_SL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLOCK_STAT_SL;
#endif
    return fapi2::getScom(i_target, CLOCK_STAT_SL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLOCK_STAT_SL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return fapi2::putScom(i_target, CLOCK_STAT_SL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_PERV_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_PERV_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_PERV_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_PERV_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_PERV_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_PERV_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_PERV_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT1_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT1_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT1_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT1_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT1_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT1_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT1_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT2_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT2_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT2_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT2_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT2_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT2_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT2_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT3_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT3_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT3_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT3_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT3_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT3_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT3_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT4_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT4_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT4_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT4_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT4_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT4_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT4_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT5_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT5_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT5_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT5_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT5_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT5_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT5_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT6_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT6_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT6_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT6_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT6_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT6_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT6_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT7_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT7_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT7_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT7_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT7_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT7_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT7_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT8_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT8_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT8_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT8_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT8_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT8_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT8_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT9_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT9_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT9_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT9_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT9_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT9_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT9_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT10_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT10_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT10_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT10_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT10_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT10_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT10_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT11_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT11_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT11_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT11_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT11_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT11_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT11_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT12_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT12_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT12_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT12_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT12_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT12_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT12_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT13_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT13_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT13_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT13_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT13_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT13_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT13_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT14_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT14_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT14_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT14_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT14_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT14_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT14_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL3_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL3_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL3_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL3_RW;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL3_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL3_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL3_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL3_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL3_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL3_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL3_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL3_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL3_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL3_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL3_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL3_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL3_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL3_WO_OR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL3_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL3_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL3_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_0_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_0_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_0_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_0_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_0_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_0_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_0_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_0_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_0_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_0_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL3_0_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_0_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_1_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_1_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_1_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_1_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_1_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_1_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_1_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_1_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_1_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_1_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL3_1_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_1_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_2_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_2_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_2_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_2_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_2_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_2_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_2_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_2_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_2_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_2_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL3_2_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_2_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_3_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_3_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_3_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_3_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_3_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_3_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_3_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_3_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_3_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_3_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL3_3_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_3_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_4_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_4_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_4_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_4_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_4_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_4_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_4_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_4_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_4_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_4_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL3_4_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_4_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_5_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_5_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_5_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_5_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_5_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_5_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_5_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_5_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_5_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_5_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL3_5_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_5_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_6_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_6_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_6_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_6_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_6_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_6_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_6_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_6_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_6_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_6_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL3_6_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_6_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_7_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_7_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_7_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_7_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_7_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_7_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_7_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_7_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_7_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_7_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL3_7_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_7_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_8_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_8_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_8_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_8_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_8_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_8_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_8_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_8_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_8_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_8_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL3_8_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_8_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_9_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_9_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_9_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_9_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_9_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_9_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_9_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_9_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_9_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_9_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL3_9_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_9_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_10_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_10_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_10_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_10_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_10_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_10_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_10_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_10_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_10_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_10_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL3_10_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_10_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_11_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_11_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_11_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_11_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_11_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_11_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_11_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_11_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_11_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_11_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL3_11_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_11_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_12_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_12_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_12_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_12_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_12_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_12_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_12_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_12_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_12_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_12_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL3_12_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_12_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_13_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_13_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_13_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_13_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_13_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_13_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_13_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_13_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_13_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_13_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL3_13_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_13_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_14_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_14_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_14_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_14_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_14_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_14_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_14_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_14_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_14_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_14_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPLT_CTRL3_14_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_14_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_DBG_INST1_COND_REG_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_DBG_INST1_COND_REG_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_DBG_INST1_COND_REG_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_DBG_INST1_COND_REG_1;
#endif
    return fapi2::getScom(i_target, EPS_DBG_INST1_COND_REG_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_DBG_INST1_COND_REG_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return fapi2::putScom(i_target, EPS_DBG_INST1_COND_REG_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_COND1_SEL_A,
           EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND1_SEL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_COND1_SEL_A,
           EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND1_SEL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_COND1_SEL_A,
           EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND1_SEL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_COND1_SEL_B,
           EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND1_SEL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_COND1_SEL_B,
           EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND1_SEL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_COND1_SEL_B,
           EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND1_SEL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_COND2_SEL_A,
           EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND2_SEL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_COND2_SEL_A,
           EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND2_SEL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_COND2_SEL_A,
           EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND2_SEL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_COND2_SEL_B,
           EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND2_SEL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_COND2_SEL_B,
           EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND2_SEL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_COND2_SEL_B,
           EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND2_SEL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT,
           EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT,
           EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT,
           EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT,
           EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT,
           EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT,
           EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT,
           EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT,
           EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST1_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT,
           EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_DBG_INST2_COND_REG_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_DBG_INST2_COND_REG_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_DBG_INST2_COND_REG_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_DBG_INST2_COND_REG_1;
#endif
    return fapi2::getScom(i_target, EPS_DBG_INST2_COND_REG_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_DBG_INST2_COND_REG_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return fapi2::putScom(i_target, EPS_DBG_INST2_COND_REG_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_COND1_SEL_A,
           EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND1_SEL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_COND1_SEL_A,
           EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND1_SEL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_COND1_SEL_A,
           EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND1_SEL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_COND1_SEL_B,
           EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND1_SEL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_COND1_SEL_B,
           EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND1_SEL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_COND1_SEL_B,
           EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND1_SEL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_COND2_SEL_A,
           EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND2_SEL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_COND2_SEL_A,
           EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND2_SEL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_COND2_SEL_A,
           EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND2_SEL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_COND2_SEL_B,
           EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND2_SEL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_COND2_SEL_B,
           EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND2_SEL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_COND2_SEL_B,
           EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND2_SEL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.setBit<EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.clearBit<EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.getBit<EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT,
           EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT,
           EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT,
           EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT,
           EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT,
           EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT,
           EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT,
           EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return o_data.insertFromRight<EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT,
           EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_INST2_COND_REG_1));
#endif
    return i_data.extractToRight<EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT,
           EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG;
#endif
    return fapi2::getScom(i_target, EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG));
#endif
    return fapi2::putScom(i_target, EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK,
           EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG));
#endif
    return o_data.insertFromRight<EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK,
           EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG));
#endif
    return i_data.extractToRight<EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK,
           EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MBA_SCOMFIR_MCWATCNTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MBA_SCOMFIR_MCWATCNTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MBA_SCOMFIR_MCWATCNTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MBA_SCOMFIR_MCWATCNTL;
#endif
    return fapi2::getScom(i_target, MBA_SCOMFIR_MCWATCNTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MBA_SCOMFIR_MCWATCNTL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return fapi2::putScom(i_target, MBA_SCOMFIR_MCWATCNTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_ENABLE_WAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_ARM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_SET_WAT_EXTERNAL_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT,
           MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT,
           MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT,
           MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RCTRL_WAT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_LOCAL_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_EXTERNAL_EVENT_TO_INTERNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCWATCNTL_RESERVED_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_RESERVED_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MBA_SCOMFIR_MCWATCNTL_RESERVED_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_0_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCWATCNTL_RESERVED_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_RESERVED_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MBA_SCOMFIR_MCWATCNTL_RESERVED_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_1_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCWATCNTL_RESERVED_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_RESERVED_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MBA_SCOMFIR_MCWATCNTL_RESERVED_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_2_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCWATCNTL_RESERVED_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_RESERVED_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MBA_SCOMFIR_MCWATCNTL_RESERVED_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT,
           MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_GLOBAL_EVENT_3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCWATCNTL_RESERVED_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_RESERVED_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MBA_SCOMFIR_MCWATCNTL_RESERVED_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_PBI_DEBUG_CAPTURE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT,
           MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT,
           MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT,
           MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RCTRL_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT,
           MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT,
           MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT,
           MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT,
           MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT,
           MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT,
           MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_EVENT_BUS_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT,
           MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT,
           MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT,
           MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG,
           MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG,
           MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG,
           MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_WAT_ON_EARLY_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59,
           MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59,
           MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59,
           MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_58_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_DBG_COUNT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_AND_22BIT_WAT_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATCNTL_RESERVED_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.setBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MBA_SCOMFIR_MCWATCNTL_RESERVED_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return o_data.clearBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATCNTL_RESERVED_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATCNTL_RESERVED_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MBA_SCOMFIR_MCWATCNTL_RESERVED_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATCNTL));
#endif
    return i_data.getBit<MBA_SCOMFIR_MCWATCNTL_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATCNTL_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MBA_SCOMFIR_MCWATDATA9(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MBA_SCOMFIR_MCWATDATA9;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MBA_SCOMFIR_MCWATDATA9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MBA_SCOMFIR_MCWATDATA9;
#endif
    return fapi2::getScom(i_target, MBA_SCOMFIR_MCWATDATA9, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MBA_SCOMFIR_MCWATDATA9(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATDATA9));
#endif
    return fapi2::putScom(i_target, MBA_SCOMFIR_MCWATDATA9, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATDATA9));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT,
           MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATDATA9));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT,
           MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATDATA9));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT,
           MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATDATA9_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATDATA9));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATDATA9_CONTROL,
           MBA_SCOMFIR_MCWATDATA9_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATDATA9_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MBA_SCOMFIR_MCWATDATA9_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATDATA9));
#endif
    return o_data.insertFromRight<MBA_SCOMFIR_MCWATDATA9_CONTROL,
           MBA_SCOMFIR_MCWATDATA9_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATDATA9_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MBA_SCOMFIR_MCWATDATA9_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MBA_SCOMFIR_MCWATDATA9));
#endif
    return i_data.extractToRight<MBA_SCOMFIR_MCWATDATA9_CONTROL,
           MBA_SCOMFIR_MCWATDATA9_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MBA_SCOMFIR_MCWATDATA9_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCFIR_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIR_RWX;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCFIR_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIR_RWX;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCFIR_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCFIR_RWX(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCFIR_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCFIR_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIR_WOX_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCFIR_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIR_WOX_AND;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCFIR_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCFIR_WOX_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCFIR_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCFIR_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIR_WOX_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCFIR_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIR_WOX_OR;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCFIR_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCFIR_WOX_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCFIR_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MULTIPLE_BAR_HIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MULTIPLE_BAR_HIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MULTIPLE_BAR_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MULTIPLE_BAR_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MULTIPLE_BAR_HIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MULTIPLE_BAR_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_RESERVED_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_RESERVED_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_RESERVED_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_RESERVED_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_RESERVED_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_RESERVED_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_RESERVED_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_RESERVED_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_RESERVED_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_RESERVED_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_RESERVED_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_RESERVED_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_RESERVED_9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_RESERVED_9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_RESERVED_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_RESERVED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_RESERVED_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_RESERVED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_RESERVED_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_RESERVED_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_RESERVED_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_RESERVED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MCS_WAT0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MCS_WAT0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MCS_WAT0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MCS_WAT0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MCS_WAT0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MCS_WAT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MCS_WAT0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_MCS_WAT0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MCS_WAT0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MCS_WAT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MCS_WAT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MCS_WAT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MCS_WAT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MCS_WAT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MCS_WAT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MCS_WAT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_MCS_WAT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MCS_WAT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MCS_WAT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MCS_WAT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MCS_WAT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MCS_WAT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MCS_WAT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MCS_WAT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MCS_WAT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_MCS_WAT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MCS_WAT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MCS_WAT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MCS_WAT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MCS_WAT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MCS_WAT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MCS_WAT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MCS_WAT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MCS_WAT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_MCS_WAT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MCS_WAT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POP_RCMD_NOHIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_POP_RCMD_NOHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POP_RCMD_NOHIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_POP_RCMD_NOHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POP_RCMD_NOHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_POP_RCMD_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_POP_RCMD_NOHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_POP_RCMD_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_POP_RCMD_NOHIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_POP_RCMD_NOHIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_POP_RCMD_NOHIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_POP_RCMD_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POP_RCMD_BADHIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_POP_RCMD_BADHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POP_RCMD_BADHIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_POP_RCMD_BADHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POP_RCMD_BADHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_POP_RCMD_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_POP_RCMD_BADHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_POP_RCMD_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_POP_RCMD_BADHIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_POP_RCMD_BADHIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_POP_RCMD_BADHIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_POP_RCMD_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_RESERVED_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_RESERVED_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_RESERVED_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_RESERVED_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_RESERVED_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_RESERVED_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_RESERVED_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_RESERVED_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_RESERVED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_RESERVED_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_RESERVED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_RESERVED_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_RESERVED_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_RESERVED_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_RESERVED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_RESERVED_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_RESERVED_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_RESERVED_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_RESERVED_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_RESERVED_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_RESERVED_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_RESERVED_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_INVALID_SMF_ACCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_INVALID_SMF_ACCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_INVALID_SMF_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_INVALID_SMF_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_INVALID_SMF_ACCESS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_INVALID_SMF_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_RESERVED_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_RESERVED_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_RESERVED_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_RESERVED_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_RESERVED_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCFIR_RESERVED_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RWX, SCOMFIR_MCFIR_WOX_AND, SCOMFIR_MCFIR_WOX_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_RESERVED_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCFIR_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCMODE1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCMODE1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCMODE1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCMODE1;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCMODE1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCMODE1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCMODE1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY,
           SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY,
           SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY,
           SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_RESERVED_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_RESERVED_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_RESERVED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_RESERVED_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_RESERVED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_RESERVED_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_RESERVED_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE1_RESERVED_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_RESERVED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS,
           SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS,
           SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS,
           SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE,
           SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE,
           SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE,
           SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH,
           SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH,
           SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH,
           SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_SPEC_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_SPEC_OP,
           SCOMFIR_MCMODE1_DISABLE_SPEC_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_SPEC_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_SPEC_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_SPEC_OP,
           SCOMFIR_MCMODE1_DISABLE_SPEC_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_SPEC_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_SPEC_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_SPEC_OP,
           SCOMFIR_MCMODE1_DISABLE_SPEC_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_SPEC_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_CI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_CI,
           SCOMFIR_MCMODE1_DISABLE_CI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_CI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_CI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_CI,
           SCOMFIR_MCMODE1_DISABLE_CI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_CI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_CI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_CI,
           SCOMFIR_MCMODE1_DISABLE_CI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_CI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS,
           SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS,
           SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS,
           SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_RESERVED_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_RESERVED_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_RESERVED_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_RESERVED_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_RESERVED_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_RESERVED_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_RESERVED_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE1_RESERVED_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_RESERVED_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_RESERVED_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_RESERVED_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_RESERVED_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_RESERVED_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_RESERVED_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SCOMFIR_MCMODE1_RESERVED_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
