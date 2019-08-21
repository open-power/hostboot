/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/nmmu/reg00012.H $         */
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

#ifndef __NMMU_REG00012_H_
#define __NMMU_REG00012_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace nmmu
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CFG_NMMU_CTL_MISC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CFG_NMMU_CTL_MISC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CFG_NMMU_CTL_MISC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CFG_NMMU_CTL_MISC;
#endif
    return fapi2::getScom(i_target, CFG_NMMU_CTL_MISC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CFG_NMMU_CTL_MISC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return fapi2::putScom(i_target, CFG_NMMU_CTL_MISC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_RESERVED_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_RESERVED_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_RESERVED_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_RESERVED_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_RESERVED_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_RESERVED_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_RESERVED_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_BKINV_INTERLOCK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_HANGP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_THRESHOLD,
           CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_THRESHOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_THRESHOLD,
           CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_THRESHOLD,
           CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_DYN_ST_MODE_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_LFSR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_LFSR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_INV_AMORT_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_RESERVED_10_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_RESERVED_10_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_10_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_RESERVED_10_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_RESERVED_10_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_10_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_RESERVED_10_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_RESERVED_10_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_10_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_RESERVED_10_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_RESERVED_10_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_10_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_RESERVED_10_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_RESERVED_10_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_10_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_RESERVED_10_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_RESERVED_10_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_10_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_DIN_ECC_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_ECC_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_XLAT_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CO_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_CKIN_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_INV_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_PROT_ERR_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_TW_TIMEOUT_CHK_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_SNP_TIMEOUT_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_FBC_CMD_PROT_ERR_CHK_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_RESERVED_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_RESERVED_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_RESERVED_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_RESERVED_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_RESERVED_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.setBit<CFG_NMMU_CTL_MISC_RESERVED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_MISC_RESERVED_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_MISC_RESERVED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_RESERVED_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_RESERVED_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_MISC_RESERVED_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.getBit<CFG_NMMU_CTL_MISC_RESERVED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT,
           CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT,
           CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT,
           CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_HANG_PLS_MULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE,
           CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE,
           CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE,
           CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_INC_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE,
           CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE,
           CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_MISC));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE,
           CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_MISC_MM_CFG_NMMU_CTL_MISC_NCU_SNP_TLBIE_DEC_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
