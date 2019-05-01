/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00035.H $         */
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

#ifndef __PROC_REG00035_H_
#define __PROC_REG00035_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_FIR_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010830;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_FIR_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010830;
#endif
    return fapi2::getScom(i_target, INT_CQ_FIR_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_FIR_RWX(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return fapi2::putScom(i_target, INT_CQ_FIR_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_FIR_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010831;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_FIR_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010831;
#endif
    return fapi2::getScom(i_target, INT_CQ_FIR_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_FIR_WOX_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return fapi2::putScom(i_target, INT_CQ_FIR_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_FIR_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010832;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_FIR_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010832;
#endif
    return fapi2::getScom(i_target, INT_CQ_FIR_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_FIR_WOX_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return fapi2::putScom(i_target, INT_CQ_FIR_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PI_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PI_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PI_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PI_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PI_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_PI_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_PI_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_PI_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PI_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PI_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_PI_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_PI_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PI_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PI_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PI_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PI_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PI_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_PI_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_PI_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_PI_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PI_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PI_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_PI_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_PI_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PI_ECC_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PI_ECC_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PI_ECC_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PI_ECC_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PI_ECC_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_PI_ECC_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_PI_ECC_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_PI_ECC_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PI_ECC_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PI_ECC_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_PI_ECC_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_PI_ECC_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PI_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PBDI_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PBDI_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PBDI_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PBDI_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PBDI_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_PBDI_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_PBDI_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_PBDI_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PBDI_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PBDI_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_PBDI_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_PBDI_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PBDI_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PBDI_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PBDI_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PBDI_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PBDI_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_PBDI_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_PBDI_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_PBDI_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PBDI_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PBDI_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_PBDI_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_PBDI_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PBDO_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PBDO_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDO_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PBDO_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PBDO_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDO_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PBDO_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_PBDO_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDO_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_PBDO_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_PBDO_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDO_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PBDO_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PBDO_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDO_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_PBDO_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_PBDO_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDO_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PBDO_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PBDO_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDO_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PBDO_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PBDO_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDO_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PBDO_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_PBDO_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDO_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_PBDO_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_PBDO_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDO_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PBDO_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PBDO_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDO_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_PBDO_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_PBDO_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PBDO_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AI_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_AI_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AI_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_AI_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AI_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_AI_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_AI_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_AI_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_AI_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_AI_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_AI_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_AI_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AI_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AI_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_AI_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AI_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_AI_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AI_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_AI_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_AI_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_AI_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_AI_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_AI_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_AI_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_AI_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AI_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_UNSOLICITED_CRESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_UNSOLICITED_CRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_UNSOLICITED_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_UNSOLICITED_CRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_UNSOLICITED_CRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_UNSOLICITED_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_UNSOLICITED_CRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_UNSOLICITED_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_UNSOLICITED_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_UNSOLICITED_CRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_UNSOLICITED_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_UNSOLICITED_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_UNSOLICITED_CRESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_UNSOLICITED_CRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_UNSOLICITED_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_UNSOLICITED_CRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_UNSOLICITED_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_UNSOLICITED_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_UNSOLICITED_PBDATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_UNSOLICITED_PBDATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_UNSOLICITED_PBDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_UNSOLICITED_PBDATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_UNSOLICITED_PBDATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_UNSOLICITED_PBDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_UNSOLICITED_PBDATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_UNSOLICITED_PBDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_UNSOLICITED_PBDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_UNSOLICITED_PBDATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_UNSOLICITED_PBDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_UNSOLICITED_PBDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_UNSOLICITED_PBDATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_UNSOLICITED_PBDATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_UNSOLICITED_PBDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_UNSOLICITED_PBDATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_UNSOLICITED_PBDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_UNSOLICITED_PBDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PC_CRD_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PC_CRD_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_CRD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PC_CRD_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PC_CRD_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_CRD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PC_CRD_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_PC_CRD_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_CRD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_PC_CRD_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_PC_CRD_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_CRD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PC_CRD_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PC_CRD_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_CRD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_PC_CRD_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_PC_CRD_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_CRD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PC_CRD_AVAIL_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PC_CRD_AVAIL_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_CRD_AVAIL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PC_CRD_AVAIL_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PC_CRD_AVAIL_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_CRD_AVAIL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PC_CRD_AVAIL_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_PC_CRD_AVAIL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_CRD_AVAIL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_PC_CRD_AVAIL_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_PC_CRD_AVAIL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_CRD_AVAIL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PC_CRD_AVAIL_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PC_CRD_AVAIL_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_CRD_AVAIL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_PC_CRD_AVAIL_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_PC_CRD_AVAIL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_CRD_AVAIL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_VC_CRD_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_VC_CRD_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_CRD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_VC_CRD_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_VC_CRD_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_CRD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_VC_CRD_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_VC_CRD_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_CRD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_VC_CRD_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_VC_CRD_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_CRD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_VC_CRD_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_VC_CRD_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_CRD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_VC_CRD_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_VC_CRD_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_CRD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_VC_CRD_AVAIL_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_VC_CRD_AVAIL_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_CRD_AVAIL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_VC_CRD_AVAIL_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_VC_CRD_AVAIL_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_CRD_AVAIL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_VC_CRD_AVAIL_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_VC_CRD_AVAIL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_CRD_AVAIL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_VC_CRD_AVAIL_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_VC_CRD_AVAIL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_CRD_AVAIL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_VC_CRD_AVAIL_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_VC_CRD_AVAIL_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_CRD_AVAIL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_VC_CRD_AVAIL_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_VC_CRD_AVAIL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_CRD_AVAIL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AIB_IN_CMD_CTL_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_AIB_IN_CMD_CTL_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_CMD_CTL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AIB_IN_CMD_CTL_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_AIB_IN_CMD_CTL_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_CMD_CTL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AIB_IN_CMD_CTL_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_AIB_IN_CMD_CTL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_CMD_CTL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_AIB_IN_CMD_CTL_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_AIB_IN_CMD_CTL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_CMD_CTL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_AIB_IN_CMD_CTL_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_AIB_IN_CMD_CTL_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_CMD_CTL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_AIB_IN_CMD_CTL_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_AIB_IN_CMD_CTL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_CMD_CTL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AIB_IN_CMD_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_AIB_IN_CMD_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_CMD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AIB_IN_CMD_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_AIB_IN_CMD_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_CMD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AIB_IN_CMD_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_AIB_IN_CMD_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_CMD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_AIB_IN_CMD_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_AIB_IN_CMD_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_CMD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_AIB_IN_CMD_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_AIB_IN_CMD_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_CMD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_AIB_IN_CMD_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_AIB_IN_CMD_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_CMD_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AIB_IN_DAT_CTL_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_AIB_IN_DAT_CTL_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_DAT_CTL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AIB_IN_DAT_CTL_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_AIB_IN_DAT_CTL_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_DAT_CTL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AIB_IN_DAT_CTL_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_AIB_IN_DAT_CTL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_DAT_CTL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_AIB_IN_DAT_CTL_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_AIB_IN_DAT_CTL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_DAT_CTL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_AIB_IN_DAT_CTL_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_AIB_IN_DAT_CTL_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_DAT_CTL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_AIB_IN_DAT_CTL_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_AIB_IN_DAT_CTL_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_IN_DAT_CTL_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PB_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PB_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PB_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PB_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PB_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_PB_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_PB_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_PB_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PB_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PB_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_PB_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_PB_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PB_RCMDX_CI_ERR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PB_RCMDX_CI_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PB_RCMDX_CI_ERR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PB_RCMDX_CI_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PB_RCMDX_CI_ERR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_PB_RCMDX_CI_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_PB_RCMDX_CI_ERR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_PB_RCMDX_CI_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PB_RCMDX_CI_ERR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PB_RCMDX_CI_ERR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_PB_RCMDX_CI_ERR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_PB_RCMDX_CI_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PB_RCMDX_CI_ERR2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PB_RCMDX_CI_ERR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PB_RCMDX_CI_ERR2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PB_RCMDX_CI_ERR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PB_RCMDX_CI_ERR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_PB_RCMDX_CI_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_PB_RCMDX_CI_ERR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_PB_RCMDX_CI_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PB_RCMDX_CI_ERR2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PB_RCMDX_CI_ERR2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_PB_RCMDX_CI_ERR2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_PB_RCMDX_CI_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PB_RCMDX_CI_ERR3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PB_RCMDX_CI_ERR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PB_RCMDX_CI_ERR3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PB_RCMDX_CI_ERR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PB_RCMDX_CI_ERR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_PB_RCMDX_CI_ERR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_PB_RCMDX_CI_ERR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_PB_RCMDX_CI_ERR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PB_RCMDX_CI_ERR3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PB_RCMDX_CI_ERR3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_PB_RCMDX_CI_ERR3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_PB_RCMDX_CI_ERR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PB_RCMDX_CI_ERR4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PB_RCMDX_CI_ERR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PB_RCMDX_CI_ERR4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PB_RCMDX_CI_ERR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PB_RCMDX_CI_ERR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_PB_RCMDX_CI_ERR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_PB_RCMDX_CI_ERR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_PB_RCMDX_CI_ERR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PB_RCMDX_CI_ERR4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PB_RCMDX_CI_ERR4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_PB_RCMDX_CI_ERR4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_PB_RCMDX_CI_ERR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PB_RCMDX_CI_ERR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_MRT_ERR_NOT_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_MRT_ERR_NOT_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_MRT_ERR_NOT_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_MRT_ERR_NOT_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_MRT_ERR_NOT_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_MRT_ERR_NOT_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_MRT_ERR_NOT_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_MRT_ERR_NOT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_MRT_ERR_NOT_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_MRT_ERR_NOT_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_MRT_ERR_NOT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_MRT_ERR_NOT_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_MRT_ERR_NOT_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_MRT_ERR_NOT_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_MRT_ERR_NOT_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_MRT_ERR_NOT_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_MRT_ERR_NOT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_MRT_ERR_NOT_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_MRT_ERR_PSIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_MRT_ERR_PSIZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_MRT_ERR_PSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_MRT_ERR_PSIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_MRT_ERR_PSIZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_MRT_ERR_PSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_MRT_ERR_PSIZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_MRT_ERR_PSIZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_MRT_ERR_PSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_MRT_ERR_PSIZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_MRT_ERR_PSIZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_MRT_ERR_PSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_MRT_ERR_PSIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_MRT_ERR_PSIZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_MRT_ERR_PSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_MRT_ERR_PSIZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_MRT_ERR_PSIZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_MRT_ERR_PSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_SCOM_S_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_SCOM_S_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_SCOM_S_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_SCOM_S_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_SCOM_S_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_SCOM_S_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_SCOM_S_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_SCOM_S_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_SCOM_S_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_SCOM_S_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_SCOM_S_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_SCOM_S_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_SCOM_S_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_SCOM_S_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_SCOM_S_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_SCOM_S_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_SCOM_S_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_SCOM_S_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_TTT_INVALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_TTT_INVALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_TTT_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_TTT_INVALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_TTT_INVALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_TTT_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_TTT_INVALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_TTT_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_TTT_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_TTT_INVALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_TTT_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_TTT_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_TTT_INVALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_TTT_INVALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_TTT_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_TTT_INVALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_TTT_INVALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_TTT_INVALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_WRQ_OP_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_WRQ_OP_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_WRQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_WRQ_OP_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_WRQ_OP_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_WRQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_WRQ_OP_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_WRQ_OP_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_WRQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_WRQ_OP_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_WRQ_OP_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_WRQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_WRQ_OP_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_WRQ_OP_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_WRQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_WRQ_OP_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_WRQ_OP_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_WRQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_RDQ_OP_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_RDQ_OP_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_RDQ_OP_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_RDQ_OP_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_RDQ_OP_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_RDQ_OP_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_RDQ_OP_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_RDQ_OP_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_RDQ_OP_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_RDQ_OP_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_RDQ_OP_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_RDQ_OP_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_INTQ_OP_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_INTQ_OP_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_INTQ_OP_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_INTQ_OP_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_INTQ_OP_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_INTQ_OP_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_INTQ_OP_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_INTQ_OP_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_INTQ_OP_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_INTQ_OP_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_INTQ_OP_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_INTQ_OP_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTQ_OP_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_RDQ_DATA_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_RDQ_DATA_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_RDQ_DATA_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_RDQ_DATA_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_RDQ_DATA_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_RDQ_DATA_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_RDQ_DATA_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_RDQ_DATA_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_RDQ_DATA_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_RDQ_DATA_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_RDQ_DATA_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_RDQ_DATA_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_STQ_DATA_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_STQ_DATA_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_STQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_STQ_DATA_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_STQ_DATA_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_STQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_STQ_DATA_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_STQ_DATA_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_STQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_STQ_DATA_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_STQ_DATA_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_STQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_STQ_DATA_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_STQ_DATA_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_STQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_STQ_DATA_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_STQ_DATA_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_STQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_LDQ_DATA_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_LDQ_DATA_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_LDQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_LDQ_DATA_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_LDQ_DATA_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_LDQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_LDQ_DATA_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_LDQ_DATA_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_LDQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_LDQ_DATA_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_LDQ_DATA_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_LDQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_LDQ_DATA_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_LDQ_DATA_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_LDQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_LDQ_DATA_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_LDQ_DATA_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_LDQ_DATA_HANG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_WRQ_BAD_CRESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_WRQ_BAD_CRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_WRQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_WRQ_BAD_CRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_WRQ_BAD_CRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_WRQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_WRQ_BAD_CRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_WRQ_BAD_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_WRQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_WRQ_BAD_CRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_WRQ_BAD_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_WRQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_WRQ_BAD_CRESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_WRQ_BAD_CRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_WRQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_WRQ_BAD_CRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_WRQ_BAD_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_WRQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_RDQ_BAD_CRESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_RDQ_BAD_CRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_RDQ_BAD_CRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_RDQ_BAD_CRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_RDQ_BAD_CRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_RDQ_BAD_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_RDQ_BAD_CRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_RDQ_BAD_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_RDQ_BAD_CRESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_RDQ_BAD_CRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_RDQ_BAD_CRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_RDQ_BAD_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_INTQ_BAD_CRESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_INTQ_BAD_CRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_INTQ_BAD_CRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_INTQ_BAD_CRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_INTQ_BAD_CRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_INTQ_BAD_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_INTQ_BAD_CRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_INTQ_BAD_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_INTQ_BAD_CRESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_INTQ_BAD_CRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_INTQ_BAD_CRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_INTQ_BAD_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTQ_BAD_CRESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_RDQ_ABORT_TRM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_RDQ_ABORT_TRM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_ABORT_TRM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_RDQ_ABORT_TRM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_RDQ_ABORT_TRM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_ABORT_TRM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_RDQ_ABORT_TRM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_RDQ_ABORT_TRM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_ABORT_TRM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_RDQ_ABORT_TRM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_RDQ_ABORT_TRM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_ABORT_TRM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_RDQ_ABORT_TRM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_RDQ_ABORT_TRM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_ABORT_TRM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_RDQ_ABORT_TRM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_RDQ_ABORT_TRM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RDQ_ABORT_TRM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_INTR_PROTOCOL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_INTR_PROTOCOL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTR_PROTOCOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_INTR_PROTOCOL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_INTR_PROTOCOL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTR_PROTOCOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_INTR_PROTOCOL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_INTR_PROTOCOL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTR_PROTOCOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_INTR_PROTOCOL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_INTR_PROTOCOL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTR_PROTOCOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_INTR_PROTOCOL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_INTR_PROTOCOL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTR_PROTOCOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_INTR_PROTOCOL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_INTR_PROTOCOL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_INTR_PROTOCOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_OP_TARGETED_SECURE_MEM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_OP_TARGETED_SECURE_MEM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_OP_TARGETED_SECURE_MEM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_OP_TARGETED_SECURE_MEM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_OP_TARGETED_SECURE_MEM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_OP_TARGETED_SECURE_MEM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_OP_TARGETED_SECURE_MEM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_OP_TARGETED_SECURE_MEM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_OP_TARGETED_SECURE_MEM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_OP_TARGETED_SECURE_MEM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_OP_TARGETED_SECURE_MEM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_OP_TARGETED_SECURE_MEM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_OP_TARGETED_SECURE_MEM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_OP_TARGETED_SECURE_MEM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_OP_TARGETED_SECURE_MEM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_OP_TARGETED_SECURE_MEM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_OP_TARGETED_SECURE_MEM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_OP_TARGETED_SECURE_MEM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AIB_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_AIB_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AIB_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_AIB_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_AIB_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_AIB_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_AIB_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_AIB_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_AIB_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_AIB_FENCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_AIB_FENCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_AIB_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_AIB_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_CFG_REG_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_CFG_REG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_CFG_REG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_CFG_REG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_CFG_REG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_CFG_REG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_CFG_REG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_CFG_REG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_CFG_REG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_CFG_REG_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_CFG_REG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_CFG_REG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_CFG_REG_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_CFG_REG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_CFG_REG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_CFG_REG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_CFG_REG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_CFG_REG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_RESERVED_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_RESERVED_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RESERVED_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_RESERVED_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_RESERVED_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RESERVED_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_RESERVED_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_RESERVED_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RESERVED_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_RESERVED_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_RESERVED_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RESERVED_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_RESERVED_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_RESERVED_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RESERVED_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_RESERVED_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_RESERVED_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_RESERVED_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_CMD_QX_SEVERE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_CMD_QX_SEVERE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_CMD_QX_SEVERE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_CMD_QX_SEVERE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_CMD_QX_SEVERE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_CMD_QX_SEVERE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_CMD_QX_SEVERE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.setBit<INT_CQ_FIR_CMD_QX_SEVERE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_CMD_QX_SEVERE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_FIR_CMD_QX_SEVERE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.clearBit<INT_CQ_FIR_CMD_QX_SEVERE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_CMD_QX_SEVERE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_CMD_QX_SEVERE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_CMD_QX_SEVERE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_CMD_QX_SEVERE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_FIR_CMD_QX_SEVERE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.getBit<INT_CQ_FIR_CMD_QX_SEVERE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_CMD_QX_SEVERE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PC_FATAL_ERROR_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PC_FATAL_ERROR_0_3,
           INT_CQ_FIR_PC_FATAL_ERROR_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_FATAL_ERROR_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PC_FATAL_ERROR_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PC_FATAL_ERROR_0_3,
           INT_CQ_FIR_PC_FATAL_ERROR_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_FATAL_ERROR_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PC_FATAL_ERROR_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PC_FATAL_ERROR_0_3,
           INT_CQ_FIR_PC_FATAL_ERROR_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_FATAL_ERROR_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PC_RECOV_ERROR_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PC_RECOV_ERROR_0_3,
           INT_CQ_FIR_PC_RECOV_ERROR_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_RECOV_ERROR_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PC_RECOV_ERROR_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PC_RECOV_ERROR_0_3,
           INT_CQ_FIR_PC_RECOV_ERROR_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_RECOV_ERROR_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PC_RECOV_ERROR_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PC_RECOV_ERROR_0_3,
           INT_CQ_FIR_PC_RECOV_ERROR_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_RECOV_ERROR_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PC_INFO_ERROR_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PC_INFO_ERROR_0_3,
           INT_CQ_FIR_PC_INFO_ERROR_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_INFO_ERROR_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_PC_INFO_ERROR_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_PC_INFO_ERROR_0_3,
           INT_CQ_FIR_PC_INFO_ERROR_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_INFO_ERROR_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_PC_INFO_ERROR_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_PC_INFO_ERROR_0_3,
           INT_CQ_FIR_PC_INFO_ERROR_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_PC_INFO_ERROR_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_VC_FATAL_ERROR_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_VC_FATAL_ERROR_0_2,
           INT_CQ_FIR_VC_FATAL_ERROR_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_FATAL_ERROR_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_VC_FATAL_ERROR_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_VC_FATAL_ERROR_0_2,
           INT_CQ_FIR_VC_FATAL_ERROR_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_FATAL_ERROR_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_VC_FATAL_ERROR_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_VC_FATAL_ERROR_0_2,
           INT_CQ_FIR_VC_FATAL_ERROR_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_FATAL_ERROR_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_VC_RECOV_ERROR_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_VC_RECOV_ERROR_0_2,
           INT_CQ_FIR_VC_RECOV_ERROR_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_RECOV_ERROR_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_VC_RECOV_ERROR_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_VC_RECOV_ERROR_0_2,
           INT_CQ_FIR_VC_RECOV_ERROR_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_RECOV_ERROR_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_VC_RECOV_ERROR_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_VC_RECOV_ERROR_0_2,
           INT_CQ_FIR_VC_RECOV_ERROR_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_RECOV_ERROR_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_VC_INFO_ERROR_0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_VC_INFO_ERROR_0_2,
           INT_CQ_FIR_VC_INFO_ERROR_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_INFO_ERROR_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_FIR_VC_INFO_ERROR_0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return o_data.insertFromRight<INT_CQ_FIR_VC_INFO_ERROR_0_2,
           INT_CQ_FIR_VC_INFO_ERROR_0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_INFO_ERROR_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_FIR_VC_INFO_ERROR_0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010832, 0x2010831, 0x2010830));
#endif
    return i_data.extractToRight<INT_CQ_FIR_VC_INFO_ERROR_0_2,
           INT_CQ_FIR_VC_INFO_ERROR_0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_FIR_VC_INFO_ERROR_0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_PM_CTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010827;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_PM_CTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010827;
#endif
    return fapi2::getScom(i_target, INT_CQ_PM_CTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_PM_CTL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return fapi2::putScom(i_target, INT_CQ_PM_CTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PM_CTL_ENABLE_0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return o_data.insertFromRight<INT_CQ_PM_CTL_ENABLE_0_7,
           INT_CQ_PM_CTL_ENABLE_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_ENABLE_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PM_CTL_ENABLE_0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return o_data.insertFromRight<INT_CQ_PM_CTL_ENABLE_0_7,
           INT_CQ_PM_CTL_ENABLE_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_ENABLE_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_PM_CTL_ENABLE_0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return i_data.extractToRight<INT_CQ_PM_CTL_ENABLE_0_7,
           INT_CQ_PM_CTL_ENABLE_0_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_ENABLE_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PM_CTL_RESET_0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return o_data.insertFromRight<INT_CQ_PM_CTL_RESET_0_7,
           INT_CQ_PM_CTL_RESET_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_RESET_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PM_CTL_RESET_0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return o_data.insertFromRight<INT_CQ_PM_CTL_RESET_0_7,
           INT_CQ_PM_CTL_RESET_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_RESET_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_PM_CTL_RESET_0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return i_data.extractToRight<INT_CQ_PM_CTL_RESET_0_7,
           INT_CQ_PM_CTL_RESET_0_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_RESET_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PM_CTL_SOURCE_SUBUNIT_0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return o_data.insertFromRight<INT_CQ_PM_CTL_SOURCE_SUBUNIT_0_1,
           INT_CQ_PM_CTL_SOURCE_SUBUNIT_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_SOURCE_SUBUNIT_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PM_CTL_SOURCE_SUBUNIT_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return o_data.insertFromRight<INT_CQ_PM_CTL_SOURCE_SUBUNIT_0_1,
           INT_CQ_PM_CTL_SOURCE_SUBUNIT_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_SOURCE_SUBUNIT_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_PM_CTL_SOURCE_SUBUNIT_0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return i_data.extractToRight<INT_CQ_PM_CTL_SOURCE_SUBUNIT_0_1,
           INT_CQ_PM_CTL_SOURCE_SUBUNIT_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_SOURCE_SUBUNIT_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PM_CTL_CQ_GROUP_SEL_0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return o_data.insertFromRight<INT_CQ_PM_CTL_CQ_GROUP_SEL_0_4,
           INT_CQ_PM_CTL_CQ_GROUP_SEL_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_CQ_GROUP_SEL_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PM_CTL_CQ_GROUP_SEL_0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return o_data.insertFromRight<INT_CQ_PM_CTL_CQ_GROUP_SEL_0_4,
           INT_CQ_PM_CTL_CQ_GROUP_SEL_0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_CQ_GROUP_SEL_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_PM_CTL_CQ_GROUP_SEL_0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return i_data.extractToRight<INT_CQ_PM_CTL_CQ_GROUP_SEL_0_4,
           INT_CQ_PM_CTL_CQ_GROUP_SEL_0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_CQ_GROUP_SEL_0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PM_CTL_RESERVED_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return o_data.insertFromRight<INT_CQ_PM_CTL_RESERVED_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PM_CTL_RESERVED_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return o_data.insertFromRight<INT_CQ_PM_CTL_RESERVED_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PM_CTL_RESERVED_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return o_data.setBit<INT_CQ_PM_CTL_RESERVED_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_PM_CTL_RESERVED_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return o_data.clearBit<INT_CQ_PM_CTL_RESERVED_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_PM_CTL_RESERVED_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return i_data.extractToRight<INT_CQ_PM_CTL_RESERVED_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_PM_CTL_RESERVED_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return i_data.getBit<INT_CQ_PM_CTL_RESERVED_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PM_CTL_COUNT_EVERY_CYCLE_0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return o_data.insertFromRight<INT_CQ_PM_CTL_COUNT_EVERY_CYCLE_0_7,
           INT_CQ_PM_CTL_COUNT_EVERY_CYCLE_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_COUNT_EVERY_CYCLE_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PM_CTL_COUNT_EVERY_CYCLE_0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return o_data.insertFromRight<INT_CQ_PM_CTL_COUNT_EVERY_CYCLE_0_7,
           INT_CQ_PM_CTL_COUNT_EVERY_CYCLE_0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_COUNT_EVERY_CYCLE_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_PM_CTL_COUNT_EVERY_CYCLE_0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010827));
#endif
    return i_data.extractToRight<INT_CQ_PM_CTL_COUNT_EVERY_CYCLE_0_7,
           INT_CQ_PM_CTL_COUNT_EVERY_CYCLE_0_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PM_CTL_COUNT_EVERY_CYCLE_0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_SWI_CMD5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010824;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_SWI_CMD5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010824;
#endif
    return fapi2::getScom(i_target, INT_CQ_SWI_CMD5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_SWI_CMD5(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010824));
#endif
    return fapi2::putScom(i_target, INT_CQ_SWI_CMD5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a88;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a88;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_CONFIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_0_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_RESERVED_0_8,
           INT_PC_NXC_REGS_CONFIG_RESERVED_0_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_0_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_0_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_RESERVED_0_8,
           INT_PC_NXC_REGS_CONFIG_RESERVED_0_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_0_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_RESERVED_0_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_RESERVED_0_8,
           INT_PC_NXC_REGS_CONFIG_RESERVED_0_8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_0_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_NRQ_CHKO_LD_SHRD_CRD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_NRQ_CHKO_LD_SHRD_CRD,
           INT_PC_NXC_REGS_CONFIG_NRQ_CHKO_LD_SHRD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_NRQ_CHKO_LD_SHRD_CRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_NRQ_CHKO_LD_SHRD_CRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_NRQ_CHKO_LD_SHRD_CRD,
           INT_PC_NXC_REGS_CONFIG_NRQ_CHKO_LD_SHRD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_NRQ_CHKO_LD_SHRD_CRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_NRQ_CHKO_LD_SHRD_CRD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_NRQ_CHKO_LD_SHRD_CRD,
           INT_PC_NXC_REGS_CONFIG_NRQ_CHKO_LD_SHRD_CRD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_NRQ_CHKO_LD_SHRD_CRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_RESERVED_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_RESERVED_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_CONFIG_RESERVED_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_CONFIG_RESERVED_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_CONFIG_RESERVED_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_RESERVED_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_RESERVED_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_CONFIG_RESERVED_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_CONFIG_RESERVED_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_LD_CHKO_SHRD_CRD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_LD_CHKO_SHRD_CRD,
           INT_PC_NXC_REGS_CONFIG_LD_CHKO_SHRD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_LD_CHKO_SHRD_CRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_LD_CHKO_SHRD_CRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_LD_CHKO_SHRD_CRD,
           INT_PC_NXC_REGS_CONFIG_LD_CHKO_SHRD_CRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_LD_CHKO_SHRD_CRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_LD_CHKO_SHRD_CRD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_LD_CHKO_SHRD_CRD,
           INT_PC_NXC_REGS_CONFIG_LD_CHKO_SHRD_CRD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_LD_CHKO_SHRD_CRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_16_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_RESERVED_16_17,
           INT_PC_NXC_REGS_CONFIG_RESERVED_16_17_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_16_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_16_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_RESERVED_16_17,
           INT_PC_NXC_REGS_CONFIG_RESERVED_16_17_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_16_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_RESERVED_16_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_RESERVED_16_17,
           INT_PC_NXC_REGS_CONFIG_RESERVED_16_17_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_16_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_CACHE_WAY_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_CACHE_WAY_ENA,
           INT_PC_NXC_REGS_CONFIG_CACHE_WAY_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_CACHE_WAY_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_CACHE_WAY_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_CACHE_WAY_ENA,
           INT_PC_NXC_REGS_CONFIG_CACHE_WAY_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_CACHE_WAY_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_CACHE_WAY_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_CACHE_WAY_ENA,
           INT_PC_NXC_REGS_CONFIG_CACHE_WAY_ENA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_CACHE_WAY_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_24_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_RESERVED_24_25,
           INT_PC_NXC_REGS_CONFIG_RESERVED_24_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_24_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_24_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_RESERVED_24_25,
           INT_PC_NXC_REGS_CONFIG_RESERVED_24_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_24_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_RESERVED_24_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_RESERVED_24_25,
           INT_PC_NXC_REGS_CONFIG_RESERVED_24_25_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_24_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_PTAG_MAX_IN_USE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_PTAG_MAX_IN_USE,
           INT_PC_NXC_REGS_CONFIG_PTAG_MAX_IN_USE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_PTAG_MAX_IN_USE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_PTAG_MAX_IN_USE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_PTAG_MAX_IN_USE,
           INT_PC_NXC_REGS_CONFIG_PTAG_MAX_IN_USE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_PTAG_MAX_IN_USE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_PTAG_MAX_IN_USE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_PTAG_MAX_IN_USE,
           INT_PC_NXC_REGS_CONFIG_PTAG_MAX_IN_USE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_PTAG_MAX_IN_USE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_RESERVED_32_33,
           INT_PC_NXC_REGS_CONFIG_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_32_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_RESERVED_32_33,
           INT_PC_NXC_REGS_CONFIG_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_RESERVED_32_33,
           INT_PC_NXC_REGS_CONFIG_RESERVED_32_33_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_CHKO_WAIT_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_CHKO_WAIT_TIMEOUT,
           INT_PC_NXC_REGS_CONFIG_CHKO_WAIT_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_CHKO_WAIT_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_CHKO_WAIT_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_CHKO_WAIT_TIMEOUT,
           INT_PC_NXC_REGS_CONFIG_CHKO_WAIT_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_CHKO_WAIT_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_CHKO_WAIT_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_CHKO_WAIT_TIMEOUT,
           INT_PC_NXC_REGS_CONFIG_CHKO_WAIT_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_CHKO_WAIT_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_RESERVED_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_RESERVED_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_CONFIG_RESERVED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_CONFIG_RESERVED_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_CONFIG_RESERVED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_RESERVED_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_RESERVED_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_CONFIG_RESERVED_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_CONFIG_RESERVED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_P0_BACK2BACK_MODE_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_P0_BACK2BACK_MODE_ENA,
           INT_PC_NXC_REGS_CONFIG_P0_BACK2BACK_MODE_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_P0_BACK2BACK_MODE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_P0_BACK2BACK_MODE_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_P0_BACK2BACK_MODE_ENA,
           INT_PC_NXC_REGS_CONFIG_P0_BACK2BACK_MODE_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_P0_BACK2BACK_MODE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_P0_BACK2BACK_MODE_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_P0_BACK2BACK_MODE_ENA,
           INT_PC_NXC_REGS_CONFIG_P0_BACK2BACK_MODE_ENA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_P0_BACK2BACK_MODE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_44_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_RESERVED_44_49,
           INT_PC_NXC_REGS_CONFIG_RESERVED_44_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_44_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_44_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_RESERVED_44_49,
           INT_PC_NXC_REGS_CONFIG_RESERVED_44_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_44_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_RESERVED_44_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_RESERVED_44_49,
           INT_PC_NXC_REGS_CONFIG_RESERVED_44_49_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_44_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_ENHANCED_HASH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_ENHANCED_HASH,
           INT_PC_NXC_REGS_CONFIG_ENHANCED_HASH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_ENHANCED_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_ENHANCED_HASH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_ENHANCED_HASH,
           INT_PC_NXC_REGS_CONFIG_ENHANCED_HASH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_ENHANCED_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_ENHANCED_HASH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_ENHANCED_HASH,
           INT_PC_NXC_REGS_CONFIG_ENHANCED_HASH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_ENHANCED_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_BG_SCAN_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_BG_SCAN_RATE,
           INT_PC_NXC_REGS_CONFIG_BG_SCAN_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_BG_SCAN_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_BG_SCAN_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_BG_SCAN_RATE,
           INT_PC_NXC_REGS_CONFIG_BG_SCAN_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_BG_SCAN_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_BG_SCAN_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_BG_SCAN_RATE,
           INT_PC_NXC_REGS_CONFIG_BG_SCAN_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_BG_SCAN_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_RESERVED_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_RESERVED_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_RESERVED_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_CONFIG_RESERVED_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_CONFIG_RESERVED_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_CONFIG_RESERVED_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_RESERVED_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_RESERVED_56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_CONFIG_RESERVED_56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_CONFIG_RESERVED_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_RESERVED_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_FORCE_INVALIDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_MAX_ENTRIES_IN_MODIFIED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_MAX_ENTRIES_IN_MODIFIED,
           INT_PC_NXC_REGS_CONFIG_MAX_ENTRIES_IN_MODIFIED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_MAX_ENTRIES_IN_MODIFIED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_CONFIG_MAX_ENTRIES_IN_MODIFIED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_CONFIG_MAX_ENTRIES_IN_MODIFIED,
           INT_PC_NXC_REGS_CONFIG_MAX_ENTRIES_IN_MODIFIED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_MAX_ENTRIES_IN_MODIFIED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_CONFIG_MAX_ENTRIES_IN_MODIFIED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a88));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_CONFIG_MAX_ENTRIES_IN_MODIFIED,
           INT_PC_NXC_REGS_CONFIG_MAX_ENTRIES_IN_MODIFIED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_CONFIG_MAX_ENTRIES_IN_MODIFIED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_PERF_EVENT_SEL_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a9a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a9a;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_PERF_EVENT_SEL_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_PERF_EVENT_SEL_3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_PERF_EVENT_SEL_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LCL_GRPSCAN_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LCL_GRPSCAN_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LCL_GRPSCAN_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LCL_GRPSCAN_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LCL_GRPSCAN_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LCL_GRPSCAN_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LCL_GRPSCAN_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LCL_GRPSCAN_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LCL_GRPSCAN_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LCL_GRPSCAN_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LCL_GRPSCAN_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LCL_GRPSCAN_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_NXC_FETCH_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_NXC_FETCH_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_NXC_FETCH_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_NXC_FETCH_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_NXC_FETCH_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_NXC_FETCH_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_NXC_FETCH_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_NXC_FETCH_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_NXC_FETCH_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_NXC_FETCH_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_NXC_FETCH_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_NXC_FETCH_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_TCTXT_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_TCTXT_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_TCTXT_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_TCTXT_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_TCTXT_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_TCTXT_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_TCTXT_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_TCTXT_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_TCTXT_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_TCTXT_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_TCTXT_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_TCTXT_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_RMT_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_RMT_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_RMT_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_RMT_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_RMT_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_RMT_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_RMT_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_RMT_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_RMT_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_RMT_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_RMT_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_RMT_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_NCKO_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_NCKO_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_NCKO_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_NCKO_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_NCKO_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_NCKO_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_NCKO_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_NCKO_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_NCKO_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_NCKO_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_NCKO_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_NCKO_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_LCL_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_LCL_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_LCL_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_LCL_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_LCL_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_LCL_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_LCL_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_LCL_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_LCL_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_LCL_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_LCL_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_LCL_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_NCKI_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_NCKI_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_NCKI_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_NCKI_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_NCKI_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_NCKI_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_NCKI_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_NCKI_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_NCKI_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_NCKI_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_NCKI_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_NCKI_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_VC_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_VC_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_VC_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_VC_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_VC_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_VC_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_VC_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_VC_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_VC_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_VC_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_VC_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_VC_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_LCL_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_LCL_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_LCL_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_LCL_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_LCL_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_LCL_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_LCL_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_LCL_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_LCL_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_LCL_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_LCL_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_RSP_LCL_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_CHKO_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_CHKO_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_CHKO_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_CHKO_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_CHKO_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_CHKO_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_CHKO_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_CHKO_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_CHKO_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_CHKO_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_CHKO_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_CHKO_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_CHKI_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_CHKI_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_CHKI_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_CHKI_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_CHKI_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_CHKI_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_CHKI_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_CHKI_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_CHKI_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_CHKI_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_CHKI_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_ST_RMT_CHKI_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_REPLAY,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_DMA_WR_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_DMA_WR_DONE,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_DMA_WR_DONE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_DMA_WR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_DMA_WR_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_DMA_WR_DONE,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_DMA_WR_DONE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_DMA_WR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_DMA_WR_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_DMA_WR_DONE,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_DMA_WR_DONE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_DMA_WR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_LCL_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a9a));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC,
           INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_PERF_EVENT_SEL_3_LD_RMT_VC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_WATCH3_DATA1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010abd;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_WATCH3_DATA1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010abd;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_WATCH3_DATA1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_WATCH3_DATA1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010abd));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_WATCH3_DATA1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_DBG_PMC_ATX1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a36;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_DBG_PMC_ATX1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010a36;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_DBG_PMC_ATX1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_DBG_PMC_ATX1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_DBG_PMC_ATX1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_0,
           INT_PC_REGS_DBG_PMC_ATX1_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_0,
           INT_PC_REGS_DBG_PMC_ATX1_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX1_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX1_0,
           INT_PC_REGS_DBG_PMC_ATX1_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_1,
           INT_PC_REGS_DBG_PMC_ATX1_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_1,
           INT_PC_REGS_DBG_PMC_ATX1_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX1_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX1_1,
           INT_PC_REGS_DBG_PMC_ATX1_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_2,
           INT_PC_REGS_DBG_PMC_ATX1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_2,
           INT_PC_REGS_DBG_PMC_ATX1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX1_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX1_2,
           INT_PC_REGS_DBG_PMC_ATX1_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_3,
           INT_PC_REGS_DBG_PMC_ATX1_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_3,
           INT_PC_REGS_DBG_PMC_ATX1_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX1_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX1_3,
           INT_PC_REGS_DBG_PMC_ATX1_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_15,
           INT_PC_REGS_DBG_PMC_ATX1_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_15,
           INT_PC_REGS_DBG_PMC_ATX1_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX1_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX1_15,
           INT_PC_REGS_DBG_PMC_ATX1_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_4R(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_4R,
           INT_PC_REGS_DBG_PMC_ATX1_4R_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_4R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_4R(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_4R,
           INT_PC_REGS_DBG_PMC_ATX1_4R_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_4R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX1_4R(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX1_4R,
           INT_PC_REGS_DBG_PMC_ATX1_4R_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_4R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_4W(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_4W,
           INT_PC_REGS_DBG_PMC_ATX1_4W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_4W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_4W(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_4W,
           INT_PC_REGS_DBG_PMC_ATX1_4W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_4W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX1_4W(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX1_4W,
           INT_PC_REGS_DBG_PMC_ATX1_4W_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_4W chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_5,
           INT_PC_REGS_DBG_PMC_ATX1_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_5,
           INT_PC_REGS_DBG_PMC_ATX1_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX1_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX1_5,
           INT_PC_REGS_DBG_PMC_ATX1_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_6,
           INT_PC_REGS_DBG_PMC_ATX1_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_6,
           INT_PC_REGS_DBG_PMC_ATX1_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX1_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX1_6,
           INT_PC_REGS_DBG_PMC_ATX1_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_7,
           INT_PC_REGS_DBG_PMC_ATX1_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_7,
           INT_PC_REGS_DBG_PMC_ATX1_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX1_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX1_7,
           INT_PC_REGS_DBG_PMC_ATX1_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_8,
           INT_PC_REGS_DBG_PMC_ATX1_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_8,
           INT_PC_REGS_DBG_PMC_ATX1_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX1_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX1_8,
           INT_PC_REGS_DBG_PMC_ATX1_8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_9,
           INT_PC_REGS_DBG_PMC_ATX1_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_9,
           INT_PC_REGS_DBG_PMC_ATX1_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX1_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX1_9,
           INT_PC_REGS_DBG_PMC_ATX1_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_10,
           INT_PC_REGS_DBG_PMC_ATX1_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_10,
           INT_PC_REGS_DBG_PMC_ATX1_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX1_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX1_10,
           INT_PC_REGS_DBG_PMC_ATX1_10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_11,
           INT_PC_REGS_DBG_PMC_ATX1_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_11,
           INT_PC_REGS_DBG_PMC_ATX1_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX1_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX1_11,
           INT_PC_REGS_DBG_PMC_ATX1_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_12,
           INT_PC_REGS_DBG_PMC_ATX1_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_12,
           INT_PC_REGS_DBG_PMC_ATX1_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX1_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX1_12,
           INT_PC_REGS_DBG_PMC_ATX1_12_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_13,
           INT_PC_REGS_DBG_PMC_ATX1_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_PMC_ATX1_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_PMC_ATX1_13,
           INT_PC_REGS_DBG_PMC_ATX1_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_PMC_ATX1_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010a36));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_PMC_ATX1_13,
           INT_PC_REGS_DBG_PMC_ATX1_13_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_PMC_ATX1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_EASC_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010968;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_EASC_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010968;
#endif
    return fapi2::getScom(i_target, INT_VC_EASC_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_EASC_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010968));
#endif
    return fapi2::putScom(i_target, INT_VC_EASC_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_CFG_RESERVED_16_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010968));
#endif
    return o_data.insertFromRight<INT_VC_EASC_CFG_RESERVED_16_25,
           INT_VC_EASC_CFG_RESERVED_16_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_CFG_RESERVED_16_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_CFG_RESERVED_16_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010968));
#endif
    return o_data.insertFromRight<INT_VC_EASC_CFG_RESERVED_16_25,
           INT_VC_EASC_CFG_RESERVED_16_25_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_CFG_RESERVED_16_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_CFG_RESERVED_16_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010968));
#endif
    return i_data.extractToRight<INT_VC_EASC_CFG_RESERVED_16_25,
           INT_VC_EASC_CFG_RESERVED_16_25_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_CFG_RESERVED_16_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_CFG_MAX_PTAG_IN_USE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010968));
#endif
    return o_data.insertFromRight<INT_VC_EASC_CFG_MAX_PTAG_IN_USE,
           INT_VC_EASC_CFG_MAX_PTAG_IN_USE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_CFG_MAX_PTAG_IN_USE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_CFG_MAX_PTAG_IN_USE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010968));
#endif
    return o_data.insertFromRight<INT_VC_EASC_CFG_MAX_PTAG_IN_USE,
           INT_VC_EASC_CFG_MAX_PTAG_IN_USE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_CFG_MAX_PTAG_IN_USE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_CFG_MAX_PTAG_IN_USE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010968));
#endif
    return i_data.extractToRight<INT_VC_EASC_CFG_MAX_PTAG_IN_USE,
           INT_VC_EASC_CFG_MAX_PTAG_IN_USE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_CFG_MAX_PTAG_IN_USE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_EASC_FLUSH_INJECT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010962;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_EASC_FLUSH_INJECT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010962;
#endif
    return fapi2::getScom(i_target, INT_VC_EASC_FLUSH_INJECT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_EASC_FLUSH_INJECT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010962));
#endif
    return fapi2::putScom(i_target, INT_VC_EASC_FLUSH_INJECT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_INJECT_BLOCKID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010962));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_INJECT_BLOCKID,
           INT_VC_EASC_FLUSH_INJECT_BLOCKID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_INJECT_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_INJECT_BLOCKID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010962));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_INJECT_BLOCKID,
           INT_VC_EASC_FLUSH_INJECT_BLOCKID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_INJECT_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_FLUSH_INJECT_BLOCKID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010962));
#endif
    return i_data.extractToRight<INT_VC_EASC_FLUSH_INJECT_BLOCKID,
           INT_VC_EASC_FLUSH_INJECT_BLOCKID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_INJECT_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_INJECT_OFFSET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010962));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_INJECT_OFFSET,
           INT_VC_EASC_FLUSH_INJECT_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_INJECT_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_INJECT_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010962));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_INJECT_OFFSET,
           INT_VC_EASC_FLUSH_INJECT_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_INJECT_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_FLUSH_INJECT_OFFSET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010962));
#endif
    return i_data.extractToRight<INT_VC_EASC_FLUSH_INJECT_OFFSET,
           INT_VC_EASC_FLUSH_INJECT_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_INJECT_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_INJECT_BLOCKID_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010962));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_INJECT_BLOCKID_MASK,
           INT_VC_EASC_FLUSH_INJECT_BLOCKID_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_INJECT_BLOCKID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_INJECT_BLOCKID_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010962));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_INJECT_BLOCKID_MASK,
           INT_VC_EASC_FLUSH_INJECT_BLOCKID_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_INJECT_BLOCKID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_FLUSH_INJECT_BLOCKID_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010962));
#endif
    return i_data.extractToRight<INT_VC_EASC_FLUSH_INJECT_BLOCKID_MASK,
           INT_VC_EASC_FLUSH_INJECT_BLOCKID_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_INJECT_BLOCKID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_INJECT_OFFSET_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010962));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_INJECT_OFFSET_MASK,
           INT_VC_EASC_FLUSH_INJECT_OFFSET_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_INJECT_OFFSET_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_INJECT_OFFSET_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010962));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_INJECT_OFFSET_MASK,
           INT_VC_EASC_FLUSH_INJECT_OFFSET_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_INJECT_OFFSET_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_FLUSH_INJECT_OFFSET_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010962));
#endif
    return i_data.extractToRight<INT_VC_EASC_FLUSH_INJECT_OFFSET_MASK,
           INT_VC_EASC_FLUSH_INJECT_OFFSET_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EASC_FLUSH_INJECT_OFFSET_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_EAS_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010909;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_EAS_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010909;
#endif
    return fapi2::getScom(i_target, INT_VC_EAS_BLOCK_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_EAS_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010909));
#endif
    return fapi2::putScom(i_target, INT_VC_EAS_BLOCK_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_EAS_BLOCK_MODE_INT_VC_EAS_BLOCK_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010909));
#endif
    return o_data.insertFromRight<INT_VC_EAS_BLOCK_MODE_INT_VC_EAS_BLOCK_MODE,
           INT_VC_EAS_BLOCK_MODE_INT_VC_EAS_BLOCK_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EAS_BLOCK_MODE_INT_VC_EAS_BLOCK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_EAS_BLOCK_MODE_INT_VC_EAS_BLOCK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010909));
#endif
    return o_data.insertFromRight<INT_VC_EAS_BLOCK_MODE_INT_VC_EAS_BLOCK_MODE,
           INT_VC_EAS_BLOCK_MODE_INT_VC_EAS_BLOCK_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EAS_BLOCK_MODE_INT_VC_EAS_BLOCK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_EAS_BLOCK_MODE_INT_VC_EAS_BLOCK_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010909));
#endif
    return i_data.extractToRight<INT_VC_EAS_BLOCK_MODE_INT_VC_EAS_BLOCK_MODE,
           INT_VC_EAS_BLOCK_MODE_INT_VC_EAS_BLOCK_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_EAS_BLOCK_MODE_INT_VC_EAS_BLOCK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_WATCH0_DATA3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20109a7;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_WATCH0_DATA3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20109a7;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_WATCH0_DATA3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_WATCH0_DATA3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20109a7));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_WATCH0_DATA3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ERR_CFG_G2R1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20109d1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ERR_CFG_G2R1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20109d1;
#endif
    return fapi2::getScom(i_target, INT_VC_ERR_CFG_G2R1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ERR_CFG_G2R1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20109d1));
#endif
    return fapi2::putScom(i_target, INT_VC_ERR_CFG_G2R1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ERR_CFG_G2R1_INT_VC_ERR_CFG_G2R1_ERROR_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20109d1));
#endif
    return o_data.insertFromRight<INT_VC_ERR_CFG_G2R1_INT_VC_ERR_CFG_G2R1_ERROR_CONFIG,
           INT_VC_ERR_CFG_G2R1_INT_VC_ERR_CFG_G2R1_ERROR_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ERR_CFG_G2R1_INT_VC_ERR_CFG_G2R1_ERROR_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ERR_CFG_G2R1_INT_VC_ERR_CFG_G2R1_ERROR_CONFIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20109d1));
#endif
    return o_data.insertFromRight<INT_VC_ERR_CFG_G2R1_INT_VC_ERR_CFG_G2R1_ERROR_CONFIG,
           INT_VC_ERR_CFG_G2R1_INT_VC_ERR_CFG_G2R1_ERROR_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ERR_CFG_G2R1_INT_VC_ERR_CFG_G2R1_ERROR_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ERR_CFG_G2R1_INT_VC_ERR_CFG_G2R1_ERROR_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20109d1));
#endif
    return i_data.extractToRight<INT_VC_ERR_CFG_G2R1_INT_VC_ERR_CFG_G2R1_ERROR_CONFIG,
           INT_VC_ERR_CFG_G2R1_INT_VC_ERR_CFG_G2R1_ERROR_CONFIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ERR_CFG_G2R1_INT_VC_ERR_CFG_G2R1_ERROR_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_BANK0_TAU(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010815;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_BANK0_TAU(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010815;
#endif
    return fapi2::getScom(i_target, MCD_BANK0_TAU, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_BANK0_TAU(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return fapi2::putScom(i_target, MCD_BANK0_TAU, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TAU_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return o_data.insertFromRight<MCD_BANK0_TAU_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TAU_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return o_data.insertFromRight<MCD_BANK0_TAU_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TAU_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return o_data.setBit<MCD_BANK0_TAU_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_TAU_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return o_data.clearBit<MCD_BANK0_TAU_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TAU_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return i_data.extractToRight<MCD_BANK0_TAU_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_TAU_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return i_data.getBit<MCD_BANK0_TAU_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TAU_CHIP_CONTAINED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return o_data.insertFromRight<MCD_BANK0_TAU_CHIP_CONTAINED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_CHIP_CONTAINED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TAU_CHIP_CONTAINED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return o_data.insertFromRight<MCD_BANK0_TAU_CHIP_CONTAINED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_CHIP_CONTAINED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TAU_CHIP_CONTAINED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return o_data.setBit<MCD_BANK0_TAU_CHIP_CONTAINED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_CHIP_CONTAINED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_TAU_CHIP_CONTAINED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return o_data.clearBit<MCD_BANK0_TAU_CHIP_CONTAINED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_CHIP_CONTAINED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TAU_CHIP_CONTAINED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return i_data.extractToRight<MCD_BANK0_TAU_CHIP_CONTAINED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_CHIP_CONTAINED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_TAU_CHIP_CONTAINED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return i_data.getBit<MCD_BANK0_TAU_CHIP_CONTAINED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_CHIP_CONTAINED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TAU_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return o_data.insertFromRight<MCD_BANK0_TAU_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TAU_SMF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return o_data.insertFromRight<MCD_BANK0_TAU_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TAU_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return o_data.setBit<MCD_BANK0_TAU_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_TAU_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return o_data.clearBit<MCD_BANK0_TAU_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TAU_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return i_data.extractToRight<MCD_BANK0_TAU_SMF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_TAU_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return i_data.getBit<MCD_BANK0_TAU_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TAU_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return o_data.insertFromRight<MCD_BANK0_TAU_GRP_SIZE,
           MCD_BANK0_TAU_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TAU_GRP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return o_data.insertFromRight<MCD_BANK0_TAU_GRP_SIZE,
           MCD_BANK0_TAU_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TAU_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return i_data.extractToRight<MCD_BANK0_TAU_GRP_SIZE,
           MCD_BANK0_TAU_GRP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TAU_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return o_data.insertFromRight<MCD_BANK0_TAU_GRP_BASE,
           MCD_BANK0_TAU_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_TAU_GRP_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return o_data.insertFromRight<MCD_BANK0_TAU_GRP_BASE,
           MCD_BANK0_TAU_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_TAU_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010815));
#endif
    return i_data.extractToRight<MCD_BANK0_TAU_GRP_BASE,
           MCD_BANK0_TAU_GRP_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_TAU_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_CFG_NMMU_CTL_SM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c52;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_CFG_NMMU_CTL_SM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c52;
#endif
    return fapi2::getScom(i_target, MM0_MM_CFG_NMMU_CTL_SM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_CFG_NMMU_CTL_SM(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return fapi2::putScom(i_target, MM0_MM_CFG_NMMU_CTL_SM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_SM_TWSM_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_SM_TWSM_DIS,
           MM0_MM_CFG_NMMU_CTL_SM_SM_TWSM_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_TWSM_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_SM_TWSM_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_SM_TWSM_DIS,
           MM0_MM_CFG_NMMU_CTL_SM_SM_TWSM_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_TWSM_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_SM_TWSM_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_SM_TWSM_DIS,
           MM0_MM_CFG_NMMU_CTL_SM_SM_TWSM_DIS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_TWSM_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_SM_CKINSM_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_SM_CKINSM_DIS,
           MM0_MM_CFG_NMMU_CTL_SM_SM_CKINSM_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_CKINSM_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_SM_CKINSM_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_SM_CKINSM_DIS,
           MM0_MM_CFG_NMMU_CTL_SM_SM_CKINSM_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_CKINSM_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_SM_CKINSM_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_SM_CKINSM_DIS,
           MM0_MM_CFG_NMMU_CTL_SM_SM_CKINSM_DIS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_CKINSM_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_INV_SINGLE_THREAD_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_CXT_CAC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_ISS487_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_SM_ISS526_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH,
           MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH,
           MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH,
           MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_CNT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_HPT_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_NIO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_ATT_RDX_TIO_FOLD_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_UPRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_ABRT_IF_PF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_LCO_RDX_PDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_INT_TLB_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_SPLIT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_RDX_PWC_VA_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_TW_PTE_UPD_INTR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.insertFromRight<MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.setBit<MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return o_data.clearBit<MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.extractToRight<MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c52));
#endif
    return i_data.getBit<MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_CFG_NMMU_CTL_SM_NCU_SNP_TLBIE_PACING_CNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_FIR1_REG_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c40;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_FIR1_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c40;
#endif
    return fapi2::getScom(i_target, MM0_MM_FIR1_REG_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_FIR1_REG_RWX(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return fapi2::putScom(i_target, MM0_MM_FIR1_REG_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_FIR1_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c41;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_FIR1_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c41;
#endif
    return fapi2::getScom(i_target, MM0_MM_FIR1_REG_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_FIR1_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return fapi2::putScom(i_target, MM0_MM_FIR1_REG_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_FIR1_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c42;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_FIR1_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c42;
#endif
    return fapi2::getScom(i_target, MM0_MM_FIR1_REG_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_FIR1_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return fapi2::putScom(i_target, MM0_MM_FIR1_REG_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_CQRD_ARY_ECC_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_PROT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_XLAT_TIMEOUT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_SLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_SLB_DIR_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_SLB_DIR_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_SLB_DIR_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_SLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_SLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_SLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_SLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_SLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_SLB_DIR_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_SLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_SLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_SLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_SLB_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_SLB_CAC_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_SLB_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_SLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_SLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_SLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_SLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_SLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_SLB_CAC_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_SLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_SLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_SLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_SLB_LRU_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_SLB_LRU_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_SLB_LRU_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_SLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_SLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_SLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_SLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_SLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_SLB_LRU_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_SLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_SLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_SLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_SLB_MULTIHIT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_SLB_MULTIHIT_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_SLB_MULTIHIT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_SLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_SLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_SLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_SLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_SLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_SLB_MULTIHIT_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_SLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_SLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TLB_DIR_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TLB_DIR_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TLB_DIR_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TLB_DIR_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TLB_DIR_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TLB_DIR_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_DIR_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TLB_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TLB_CAC_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TLB_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TLB_CAC_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TLB_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TLB_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TLB_LRU_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TLB_LRU_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TLB_LRU_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TLB_LRU_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TLB_LRU_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TLB_LRU_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_LRU_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TLB_MULTIHIT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TLB_MULTIHIT_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TLB_MULTIHIT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TLB_MULTIHIT_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TLB_MULTIHIT_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TLB_MULTIHIT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TLB_MULTIHIT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_SEG_FAULT_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_SEG_FAULT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_SEG_FAULT_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_SEG_FAULT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_SEG_FAULT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_SEG_FAULT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_SEG_FAULT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_SEG_FAULT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_SEG_FAULT_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_SEG_FAULT_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_SEG_FAULT_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_SEG_FAULT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_SEG_FAULT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_NOPTE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_BPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_VPCHK_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PG_FAULT_SEID_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_ADD_ERR_CR_RD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PTE_UPD_FAIL_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_ADD_ERR_CR_WR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_CFG_GUEST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_CFG_HOST_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_INVALID_WIMG_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_INV_RDX_QUAD_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_FOREIGN_ADDR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_PREFETCH_ABT_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_CXT_CAC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_RDX_PWC_PERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CO_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CI_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_INV_SM_CTL_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_TW_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CO_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CI_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_INV_TIMEOUT_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_NX0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CP0_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_CP1_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_NPU_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_FBC_LXSTOP_ERR_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.insertFromRight<MM0_MM_FIR1_REG_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_FIR1_REG_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.setBit<MM0_MM_FIR1_REG_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MM0_MM_FIR1_REG_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return o_data.clearBit<MM0_MM_FIR1_REG_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_FIR1_REG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.extractToRight<MM0_MM_FIR1_REG_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MM0_MM_FIR1_REG_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c42, 0x2010c41, 0x2010c40));
#endif
    return i_data.getBit<MM0_MM_FIR1_REG_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_FIR1_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_FIR1_WOF_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c48;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_FIR1_WOF_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c48;
#endif
    return fapi2::getScom(i_target, MM0_MM_FIR1_WOF_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_FIR1_WOF_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c48));
#endif
    return fapi2::putScom(i_target, MM0_MM_FIR1_WOF_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM0_MM_NMMU_PMU1_CNT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c50;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM0_MM_NMMU_PMU1_CNT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2010c50;
#endif
    return fapi2::getScom(i_target, MM0_MM_NMMU_PMU1_CNT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM0_MM_NMMU_PMU1_CNT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2010c50));
#endif
    return fapi2::putScom(i_target, MM0_MM_NMMU_PMU1_CNT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM0_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c50));
#endif
    return o_data.insertFromRight<MM0_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT,
           MM0_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM0_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c50));
#endif
    return o_data.insertFromRight<MM0_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT,
           MM0_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM0_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2010c50));
#endif
    return i_data.extractToRight<MM0_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT,
           MM0_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM0_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MM1_MM_NMMU_PMU1_CNT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010c50;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MM1_MM_NMMU_PMU1_CNT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3010c50;
#endif
    return fapi2::getScom(i_target, MM1_MM_NMMU_PMU1_CNT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MM1_MM_NMMU_PMU1_CNT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3010c50));
#endif
    return fapi2::putScom(i_target, MM1_MM_NMMU_PMU1_CNT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MM1_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c50));
#endif
    return o_data.insertFromRight<MM1_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT,
           MM1_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MM1_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c50));
#endif
    return o_data.insertFromRight<MM1_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT,
           MM1_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MM1_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3010c50));
#endif
    return i_data.extractToRight<MM1_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT,
           MM1_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MM1_MM_NMMU_PMU1_CNT_REG_MM_PMU1_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_DBG_DMA_ENG_FIR_MASK_SCOM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011103;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_DBG_DMA_ENG_FIR_MASK_SCOM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011103;
#endif
    return fapi2::getScom(i_target, NX_DBG_DMA_ENG_FIR_MASK_SCOM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_DBG_DMA_ENG_FIR_MASK_SCOM(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011105, 0x2011104, 0x2011103));
#endif
    return fapi2::putScom(i_target, NX_DBG_DMA_ENG_FIR_MASK_SCOM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_DBG_DMA_ENG_FIR_MASK_SCOM1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011104;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_DBG_DMA_ENG_FIR_MASK_SCOM1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011104;
#endif
    return fapi2::getScom(i_target, NX_DBG_DMA_ENG_FIR_MASK_SCOM1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_DBG_DMA_ENG_FIR_MASK_SCOM1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011105, 0x2011104, 0x2011103));
#endif
    return fapi2::putScom(i_target, NX_DBG_DMA_ENG_FIR_MASK_SCOM1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_DBG_DMA_ENG_FIR_MASK_SCOM2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011105;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_DBG_DMA_ENG_FIR_MASK_SCOM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011105;
#endif
    return fapi2::getScom(i_target, NX_DBG_DMA_ENG_FIR_MASK_SCOM2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_DBG_DMA_ENG_FIR_MASK_SCOM2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011105, 0x2011104, 0x2011103));
#endif
    return fapi2::putScom(i_target, NX_DBG_DMA_ENG_FIR_MASK_SCOM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_DBG_DMA_ENG_FIR_MASK_NX_DMA_ENG_FIR_MASK_BITS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011105, 0x2011104, 0x2011103));
#endif
    return o_data.insertFromRight<NX_DBG_DMA_ENG_FIR_MASK_NX_DMA_ENG_FIR_MASK_BITS,
           NX_DBG_DMA_ENG_FIR_MASK_NX_DMA_ENG_FIR_MASK_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DBG_DMA_ENG_FIR_MASK_NX_DMA_ENG_FIR_MASK_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DBG_DMA_ENG_FIR_MASK_NX_DMA_ENG_FIR_MASK_BITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011105, 0x2011104, 0x2011103));
#endif
    return o_data.insertFromRight<NX_DBG_DMA_ENG_FIR_MASK_NX_DMA_ENG_FIR_MASK_BITS,
           NX_DBG_DMA_ENG_FIR_MASK_NX_DMA_ENG_FIR_MASK_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DBG_DMA_ENG_FIR_MASK_NX_DMA_ENG_FIR_MASK_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DBG_DMA_ENG_FIR_MASK_NX_DMA_ENG_FIR_MASK_BITS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011105, 0x2011104, 0x2011103));
#endif
    return i_data.extractToRight<NX_DBG_DMA_ENG_FIR_MASK_NX_DMA_ENG_FIR_MASK_BITS,
           NX_DBG_DMA_ENG_FIR_MASK_NX_DMA_ENG_FIR_MASK_BITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DBG_DMA_ENG_FIR_MASK_NX_DMA_ENG_FIR_MASK_BITS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_UMAC_SU_ERAT_ERROR_RPT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110d7;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_UMAC_SU_ERAT_ERROR_RPT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110d7;
#endif
    return fapi2::getScom(i_target, NX_PBI_UMAC_SU_ERAT_ERROR_RPT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_UMAC_SU_ERAT_ERROR_RPT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20110d7));
#endif
    return fapi2::putScom(i_target, NX_PBI_UMAC_SU_ERAT_ERROR_RPT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_SU_ERAT_ERROR_RPT_ERAT_ERROR_RPT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110d7));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_SU_ERAT_ERROR_RPT_ERAT_ERROR_RPT,
           NX_PBI_UMAC_SU_ERAT_ERROR_RPT_ERAT_ERROR_RPT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SU_ERAT_ERROR_RPT_ERAT_ERROR_RPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_SU_ERAT_ERROR_RPT_ERAT_ERROR_RPT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110d7));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_SU_ERAT_ERROR_RPT_ERAT_ERROR_RPT,
           NX_PBI_UMAC_SU_ERAT_ERROR_RPT_ERAT_ERROR_RPT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SU_ERAT_ERROR_RPT_ERAT_ERROR_RPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_SU_ERAT_ERROR_RPT_ERAT_ERROR_RPT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110d7));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_SU_ERAT_ERROR_RPT_ERAT_ERROR_RPT,
           NX_PBI_UMAC_SU_ERAT_ERROR_RPT_ERAT_ERROR_RPT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SU_ERAT_ERROR_RPT_ERAT_ERROR_RPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110c7;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110c7;
#endif
    return fapi2::getScom(i_target, NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20110c7));
#endif
    return fapi2::putScom(i_target, NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_LPID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c7));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_LPID,
           NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_LPID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_LPID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_LPID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c7));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_LPID,
           NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_LPID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_LPID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_LPID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c7));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_LPID,
           NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_LPID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_LPID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_PID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c7));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_PID,
           NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_PID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_PID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_PID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c7));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_PID,
           NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_PID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_PID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_PID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c7));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_PID,
           NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_PID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_PID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_TID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c7));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_TID,
           NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_TID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_TID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_TID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c7));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_TID,
           NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_TID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_TID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_TID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c7));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_TID,
           NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_TID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_TID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c7));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c7));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c7));
#endif
    return o_data.setBit<NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c7));
#endif
    return o_data.clearBit<NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c7));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110c7));
#endif
    return i_data.getBit<NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110ca;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20110ca;
#endif
    return fapi2::getScom(i_target, NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20110ca));
#endif
    return fapi2::putScom(i_target, NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110ca));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR,
           NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110ca));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR,
           NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110ca));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR,
           NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110ca));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_SIZE,
           NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_SIZE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_SIZE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110ca));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_SIZE,
           NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_SIZE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20110ca));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_SIZE,
           NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_SYM_LO_PRIOR_RCV_FIFO_BAR_SYM_LO_PRIORITY_RCV_FIFO_BAR_SIZE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_ES3_EVENT_COMPB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x39c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_ES3_EVENT_COMPB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x39c;
#endif
    return fapi2::getScom(i_target, PB_COM_ES3_EVENT_COMPB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_ES3_EVENT_COMPB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return fapi2::putScom(i_target, PB_COM_ES3_EVENT_COMPB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_TTYPE_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_TTYPE_ES3,
           PB_COM_ES3_EVENT_COMPB_TTYPE_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TTYPE_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_TTYPE_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_TTYPE_ES3,
           PB_COM_ES3_EVENT_COMPB_TTYPE_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TTYPE_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_COMPB_TTYPE_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_COMPB_TTYPE_ES3,
           PB_COM_ES3_EVENT_COMPB_TTYPE_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TTYPE_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_TTYPE_MASK_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_TTYPE_MASK_ES3,
           PB_COM_ES3_EVENT_COMPB_TTYPE_MASK_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TTYPE_MASK_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_TTYPE_MASK_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_TTYPE_MASK_ES3,
           PB_COM_ES3_EVENT_COMPB_TTYPE_MASK_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TTYPE_MASK_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_COMPB_TTYPE_MASK_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_COMPB_TTYPE_MASK_ES3,
           PB_COM_ES3_EVENT_COMPB_TTYPE_MASK_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TTYPE_MASK_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_TSIZE_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_TSIZE_ES3,
           PB_COM_ES3_EVENT_COMPB_TSIZE_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TSIZE_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_TSIZE_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_TSIZE_ES3,
           PB_COM_ES3_EVENT_COMPB_TSIZE_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TSIZE_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_COMPB_TSIZE_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_COMPB_TSIZE_ES3,
           PB_COM_ES3_EVENT_COMPB_TSIZE_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TSIZE_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_TSIZE_MASK_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_TSIZE_MASK_ES3,
           PB_COM_ES3_EVENT_COMPB_TSIZE_MASK_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TSIZE_MASK_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_TSIZE_MASK_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_TSIZE_MASK_ES3,
           PB_COM_ES3_EVENT_COMPB_TSIZE_MASK_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TSIZE_MASK_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_COMPB_TSIZE_MASK_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_COMPB_TSIZE_MASK_ES3,
           PB_COM_ES3_EVENT_COMPB_TSIZE_MASK_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TSIZE_MASK_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_TTAG_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_TTAG_ES3,
           PB_COM_ES3_EVENT_COMPB_TTAG_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TTAG_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_TTAG_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_TTAG_ES3,
           PB_COM_ES3_EVENT_COMPB_TTAG_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TTAG_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_COMPB_TTAG_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_COMPB_TTAG_ES3,
           PB_COM_ES3_EVENT_COMPB_TTAG_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TTAG_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_TTAG_MASK_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_TTAG_MASK_ES3,
           PB_COM_ES3_EVENT_COMPB_TTAG_MASK_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TTAG_MASK_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_TTAG_MASK_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_TTAG_MASK_ES3,
           PB_COM_ES3_EVENT_COMPB_TTAG_MASK_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TTAG_MASK_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_COMPB_TTAG_MASK_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_COMPB_TTAG_MASK_ES3,
           PB_COM_ES3_EVENT_COMPB_TTAG_MASK_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_TTAG_MASK_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_CRESP_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_CRESP_ES3,
           PB_COM_ES3_EVENT_COMPB_CRESP_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_CRESP_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_CRESP_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_CRESP_ES3,
           PB_COM_ES3_EVENT_COMPB_CRESP_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_CRESP_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_COMPB_CRESP_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_COMPB_CRESP_ES3,
           PB_COM_ES3_EVENT_COMPB_CRESP_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_CRESP_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_CRESP_MASK_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_CRESP_MASK_ES3,
           PB_COM_ES3_EVENT_COMPB_CRESP_MASK_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_CRESP_MASK_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_CRESP_MASK_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_CRESP_MASK_ES3,
           PB_COM_ES3_EVENT_COMPB_CRESP_MASK_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_CRESP_MASK_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_COMPB_CRESP_MASK_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_COMPB_CRESP_MASK_ES3,
           PB_COM_ES3_EVENT_COMPB_CRESP_MASK_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_CRESP_MASK_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.setBit<PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.clearBit<PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return i_data.getBit<PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_CRESP_POLARITY_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_SCOPE_ES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_SCOPE_ES3,
           PB_COM_ES3_EVENT_COMPB_SCOPE_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_SCOPE_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_ES3_EVENT_COMPB_SCOPE_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return o_data.insertFromRight<PB_COM_ES3_EVENT_COMPB_SCOPE_ES3,
           PB_COM_ES3_EVENT_COMPB_SCOPE_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_SCOPE_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_ES3_EVENT_COMPB_SCOPE_ES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x39c));
#endif
    return i_data.extractToRight<PB_COM_ES3_EVENT_COMPB_SCOPE_ES3,
           PB_COM_ES3_EVENT_COMPB_SCOPE_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_ES3_EVENT_COMPB_SCOPE_ES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PMU2_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1001181d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PMU2_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1001181d;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PMU2_TLPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PMU2_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1001181d));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PMU2_TLPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_TL_LINK_DLY_0123_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1001180e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_TL_LINK_DLY_0123_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1001180e;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_TL_LINK_DLY_0123_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_TL_LINK_DLY_0123_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1001180e));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_TL_LINK_DLY_0123_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_CFG_CNPM_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1101181f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_CFG_CNPM_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1101181f;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_CFG_CNPM_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_CFG_CNPM_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_CFG_CNPM_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.setBit<PB_PTLSCOM23_CFG_CNPM_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_CFG_CNPM_REG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.clearBit<PB_PTLSCOM23_CFG_CNPM_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_CFG_CNPM_REG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.getBit<PB_PTLSCOM23_CFG_CNPM_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.setBit<PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.clearBit<PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.getBit<PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.setBit<PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.clearBit<PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.getBit<PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.setBit<PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.clearBit<PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.getBit<PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.setBit<PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.clearBit<PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.getBit<PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.setBit<PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.clearBit<PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.getBit<PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_0_1_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_0_1_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_0_1_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_0_1_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_0_1_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_0_1_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_0_1_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_0_1_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_0_1_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_0_1_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_0_1_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_0_1_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_2_3_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_2_3_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_2_3_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_2_3_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_2_3_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_2_3_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_2_3_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_2_3_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_2_3_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_2_3_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_2_3_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_2_3_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_4_5_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_4_5_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_4_5_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_4_5_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_4_5_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_4_5_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_4_5_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_4_5_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_4_5_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_4_5_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_4_5_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_4_5_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_6_7_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_6_7_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_6_7_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_6_7_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_6_7_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_6_7_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_6_7_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_6_7_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_6_7_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_6_7_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_6_7_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_6_7_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_8_9_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_8_9_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_8_9_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_8_9_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_8_9_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_8_9_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_8_9_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_8_9_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_8_9_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_8_9_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_8_9_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_8_9_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_10_11_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_10_11_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_10_11_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_10_11_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_10_11_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_10_11_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_10_11_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_10_11_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_10_11_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_10_11_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_10_11_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_10_11_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_12_13_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_12_13_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_12_13_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_12_13_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_12_13_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_12_13_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_12_13_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_12_13_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_12_13_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_12_13_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_12_13_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_12_13_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_14_15_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_14_15_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_14_15_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_14_15_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_14_15_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_14_15_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_14_15_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_14_15_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_14_15_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_14_15_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_14_15_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_14_15_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_16_17_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_16_17_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_16_17_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_16_17_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_16_17_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_16_17_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_16_17_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_16_17_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_16_17_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_16_17_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_16_17_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_16_17_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_18_19_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_18_19_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_18_19_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_18_19_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_18_19_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_18_19_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_18_19_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_18_19_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_18_19_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_18_19_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_18_19_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_18_19_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_20_21_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_20_21_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_20_21_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_20_21_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_20_21_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_20_21_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_20_21_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_20_21_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_20_21_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_20_21_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_20_21_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_20_21_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_22_23_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_22_23_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_22_23_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_22_23_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_22_23_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_22_23_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_22_23_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_22_23_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_22_23_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_22_23_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_22_23_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_22_23_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_24_25_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_24_25_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_24_25_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_24_25_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_24_25_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_24_25_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_24_25_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_24_25_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_24_25_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_24_25_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_24_25_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_24_25_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_26_27_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_26_27_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_26_27_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_26_27_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_26_27_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_26_27_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_26_27_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_26_27_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_26_27_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_26_27_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_26_27_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_26_27_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_28_29_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_28_29_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_28_29_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_28_29_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_28_29_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_28_29_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_28_29_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_28_29_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_28_29_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_28_29_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_28_29_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_28_29_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_30_31_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_30_31_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_30_31_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_30_31_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_30_31_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_30_31_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_30_31_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_30_31_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_30_31_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_30_31_OP,
           PB_PTLSCOM23_CFG_CNPM_REG_30_31_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_30_31_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU0,
           PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU0,
           PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU0,
           PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU1,
           PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU1,
           PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU1,
           PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU2,
           PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU2,
           PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU2,
           PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU3,
           PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU3,
           PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU3,
           PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_CASCADE_PMU3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_SPARE,
           PB_PTLSCOM23_CFG_CNPM_REG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_CFG_CNPM_REG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_CFG_CNPM_REG_SPARE,
           PB_PTLSCOM23_CFG_CNPM_REG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_CFG_CNPM_REG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x1101181f));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_CFG_CNPM_REG_SPARE,
           PB_PTLSCOM23_CFG_CNPM_REG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_CFG_CNPM_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PMU0_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1101181b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PMU0_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1101181b;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PMU0_TLPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PMU0_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1101181b));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PMU0_TLPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_TL_LINK_SYN_23_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011813;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_TL_LINK_SYN_23_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x12011813;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_TL_LINK_SYN_23_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_TL_LINK_SYN_23_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x12011813));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_TL_LINK_SYN_23_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_PSAVE01_MODE_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011814;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_PSAVE01_MODE_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x13011814;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_PSAVE01_MODE_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_PSAVE01_MODE_CFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x13011814));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_PSAVE01_MODE_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PSAVE01_MODE_CFG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011814));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PSAVE01_MODE_CFG_MODE,
           PB_PTLSCOM67_PSAVE01_MODE_CFG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE01_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PSAVE01_MODE_CFG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011814));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PSAVE01_MODE_CFG_MODE,
           PB_PTLSCOM67_PSAVE01_MODE_CFG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE01_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PSAVE01_MODE_CFG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011814));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PSAVE01_MODE_CFG_MODE,
           PB_PTLSCOM67_PSAVE01_MODE_CFG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE01_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PSAVE01_MODE_CFG_WIDTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011814));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PSAVE01_MODE_CFG_WIDTH,
           PB_PTLSCOM67_PSAVE01_MODE_CFG_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE01_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PSAVE01_MODE_CFG_WIDTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011814));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PSAVE01_MODE_CFG_WIDTH,
           PB_PTLSCOM67_PSAVE01_MODE_CFG_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE01_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PSAVE01_MODE_CFG_WIDTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011814));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PSAVE01_MODE_CFG_WIDTH,
           PB_PTLSCOM67_PSAVE01_MODE_CFG_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE01_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PSAVE01_MODE_CFG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011814));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PSAVE01_MODE_CFG_SPARE,
           PB_PTLSCOM67_PSAVE01_MODE_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE01_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PSAVE01_MODE_CFG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011814));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PSAVE01_MODE_CFG_SPARE,
           PB_PTLSCOM67_PSAVE01_MODE_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE01_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PSAVE01_MODE_CFG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011814));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PSAVE01_MODE_CFG_SPARE,
           PB_PTLSCOM67_PSAVE01_MODE_CFG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE01_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PSAVE01_MODE_CFG_MIN_RAND_UC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011814));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PSAVE01_MODE_CFG_MIN_RAND_UC,
           PB_PTLSCOM67_PSAVE01_MODE_CFG_MIN_RAND_UC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE01_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PSAVE01_MODE_CFG_MIN_RAND_UC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011814));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PSAVE01_MODE_CFG_MIN_RAND_UC,
           PB_PTLSCOM67_PSAVE01_MODE_CFG_MIN_RAND_UC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE01_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PSAVE01_MODE_CFG_MIN_RAND_UC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x13011814));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PSAVE01_MODE_CFG_MIN_RAND_UC,
           PB_PTLSCOM67_PSAVE01_MODE_CFG_MIN_RAND_UC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_PSAVE01_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x30120c5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x30120c5;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_TRIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_TRIG,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_TRIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_TRIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_TRIG,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_TRIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_TRIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_TRIG,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_TRIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_MARK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_MARK,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_MARK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_MARK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_MARK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_MARK,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_MARK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_MARK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_MARK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_MARK,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_MARK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_MARK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG0_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_DBG1_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_RUN_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_OTHER_DBG0_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1012(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1012,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1012_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1012 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1012(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1012,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1012_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1012 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1012(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1012,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1012_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1012 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_XSTOP_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1415(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1415,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1415_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1415 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1415(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1415,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1415_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1415 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1415(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x30120c5));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1415,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1415_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_CTRL_SPARE1415 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x801084d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x801084d;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCA,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCA,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCA,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCR,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCR,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCR,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_0_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCA,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCA,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCA,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCR,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCR,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCR,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_1_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCA,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCA,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCA,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCR,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCR,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCR,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_2_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCA,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCA,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCA,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCR,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCR,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801084d));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCR,
           PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_0_PBAIBTXCCR_REG_3_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x801088e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x801088e;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x801088e));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801088e));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_A,
           PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801088e));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_A,
           PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801088e));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_A,
           PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_R(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801088e));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_R,
           PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_R_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_R(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801088e));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_R,
           PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_R_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_R(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801088e));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_R,
           PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_R_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PBAIBTXDCR_REG_R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x801088a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x801088a;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x801088a));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801088a));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801088a));
#endif
    return o_data.insertFromRight<PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801088a));
#endif
    return o_data.setBit<PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801088a));
#endif
    return o_data.clearBit<PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801088a));
#endif
    return i_data.extractToRight<PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x801088a));
#endif
    return i_data.getBit<PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBAIB_REGS_STACK_1_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBAIB_REGS_STACK_2_RESERVED1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x80108cc;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBAIB_REGS_STACK_2_RESERVED1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x80108cc;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBAIB_REGS_STACK_2_RESERVED1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBAIB_REGS_STACK_2_RESERVED1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x80108cc));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBAIB_REGS_STACK_2_RESERVED1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011811;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011811;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_MODE,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_MODE,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_MODE,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_DISABLE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MIN_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MIN_CYCLES,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MIN_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MIN_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MIN_CYCLES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MIN_CYCLES,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MIN_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MIN_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MIN_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MIN_CYCLES,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MIN_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MIN_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MAX_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MAX_CYCLES,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MAX_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MAX_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MAX_CYCLES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MAX_CYCLES,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MAX_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MAX_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MAX_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MAX_CYCLES,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MAX_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_GROUP_MAX_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MIN_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MIN_CYCLES,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MIN_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MIN_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MIN_CYCLES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MIN_CYCLES,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MIN_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MIN_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MIN_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MIN_CYCLES,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MIN_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MIN_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MAX_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MAX_CYCLES,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MAX_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MAX_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MAX_CYCLES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MAX_CYCLES,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MAX_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MAX_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MAX_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MAX_CYCLES,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MAX_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_SYSTEM_MAX_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_CLEAN_RANGES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_CLEAN_RANGES,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_CLEAN_RANGES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_CLEAN_RANGES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_CLEAN_RANGES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_CLEAN_RANGES,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_CLEAN_RANGES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_CLEAN_RANGES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_CLEAN_RANGES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_CLEAN_RANGES,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_CLEAN_RANGES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_CLEAN_RANGES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_HPCACK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_HPCACK,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_HPCACK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_HPCACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_HPCACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_HPCACK,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_HPCACK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_HPCACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_HPCACK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011811));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_HPCACK,
           PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_HPCACK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_NUM_OF_HPCACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRWOF_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011848;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRWOF_REG(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011848;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRWOF_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRWOF_REG(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011848));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_NFIRWOF_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011857;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011857;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool
GET_PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011857));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011893;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011893;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011893));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG_PE_INT_BAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011893));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG_PE_INT_BAR,
           PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG_PE_INT_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG_PE_INT_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG_PE_INT_BAR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011893));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG_PE_INT_BAR,
           PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG_PE_INT_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG_PE_INT_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG_PE_INT_BAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011893));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG_PE_INT_BAR,
           PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG_PE_INT_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_INTBAR_REG_PE_INT_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011883;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011883;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011885, 0x2011884, 0x2011883));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_WO_AND(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011884;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_WO_AND(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011884;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_WO_AND(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011885, 0x2011884, 0x2011883));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_WO_OR(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011885;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_WO_OR(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x2011885;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_WO_OR(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x2011885, 0x2011884, 0x2011883));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_NFIRMASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011885, 0x2011884, 0x2011883));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_NFIRMASK,
           PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_NFIRMASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_NFIRMASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_NFIRMASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011885, 0x2011884, 0x2011883));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_NFIRMASK,
           PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_NFIRMASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_NFIRMASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_NFIRMASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x2011885, 0x2011884, 0x2011883));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_NFIRMASK,
           PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_NFIRMASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_1_REGS_NFIRMASK_REG_NFIRMASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20118cc;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20118cc;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20118cc));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20118cc));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20118cc));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20118cc));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20118cc));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20118cc));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20118cc));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_INBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20118cc));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20118cc));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20118cc));
#endif
    return o_data.setBit<PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20118cc));
#endif
    return o_data.clearBit<PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20118cc));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20118cc));
#endif
    return i_data.getBit<PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_CQSTAT_REG_OUTBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20118d2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x20118d2;
#endif
    return fapi2::getScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x20118d2));
#endif
    return fapi2::putScom(i_target, PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG_PE_PHB_BAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20118d2));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG_PE_PHB_BAR,
           PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG_PE_PHB_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG_PE_PHB_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG_PE_PHB_BAR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20118d2));
#endif
    return o_data.insertFromRight<PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG_PE_PHB_BAR,
           PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG_PE_PHB_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG_PE_PHB_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG_PE_PHB_BAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x20118d2));
#endif
    return i_data.extractToRight<PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG_PE_PHB_BAR,
           PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG_PE_PHB_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_PHBBAR_REG_PE_PHB_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010906;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010906;
#endif
    return fapi2::getScom(i_target, PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return fapi2::putScom(i_target, PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return o_data.setBit<PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return o_data.clearBit<PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return i_data.getBit<PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE,
           PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return o_data.insertFromRight<PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE,
           PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return i_data.extractToRight<PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE,
           PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PHB0_ETUX16_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010913;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PHB0_ETUX16_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010913;
#endif
    return fapi2::getScom(i_target, PE0_PHB0_ETUX16_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PHB0_ETUX16_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8010913));
#endif
    return fapi2::putScom(i_target, PE0_PHB0_ETUX16_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x946;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x946;
#endif
    return fapi2::getScom(i_target, PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x946));
#endif
    return fapi2::putScom(i_target, PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x946));
#endif
    return o_data.insertFromRight<PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x946));
#endif
    return o_data.insertFromRight<PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x946));
#endif
    return o_data.setBit<PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x946));
#endif
    return o_data.clearBit<PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x946));
#endif
    return i_data.extractToRight<PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x946));
#endif
    return i_data.getBit<PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x946));
#endif
    return o_data.insertFromRight<PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE,
           PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x946));
#endif
    return o_data.insertFromRight<PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE,
           PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x946));
#endif
    return i_data.extractToRight<PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE,
           PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x987;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x987;
#endif
    return fapi2::getScom(i_target, PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x987));
#endif
    return fapi2::putScom(i_target, PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x987));
#endif
    return o_data.insertFromRight<PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE,
           PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x987));
#endif
    return o_data.insertFromRight<PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE,
           PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x987));
#endif
    return i_data.extractToRight<PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE,
           PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x982;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x982;
#endif
    return fapi2::getScom(i_target, PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return fapi2::putScom(i_target, PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return o_data.insertFromRight<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return o_data.insertFromRight<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return o_data.setBit<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return o_data.clearBit<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return i_data.extractToRight<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return i_data.getBit<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return o_data.insertFromRight<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return o_data.insertFromRight<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return o_data.setBit<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return o_data.clearBit<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return i_data.extractToRight<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return i_data.getBit<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return o_data.insertFromRight<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return o_data.insertFromRight<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return o_data.setBit<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return o_data.clearBit<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return i_data.extractToRight<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return i_data.getBit<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return o_data.insertFromRight<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE,
           PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return o_data.insertFromRight<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE,
           PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x982));
#endif
    return i_data.extractToRight<PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE,
           PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE0_PHB2_ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE1_PB_PBAIB_REGS_STACK_2_PFIRWOF_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x90108c8;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE1_PB_PBAIB_REGS_STACK_2_PFIRWOF_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x90108c8;
#endif
    return fapi2::getScom(i_target, PE1_PB_PBAIB_REGS_STACK_2_PFIRWOF_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE1_PB_PBAIB_REGS_STACK_2_PFIRWOF_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x90108c8));
#endif
    return fapi2::putScom(i_target, PE1_PB_PBAIB_REGS_STACK_2_PFIRWOF_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3011809;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3011809;
#endif
    return fapi2::getScom(i_target, PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3011809));
#endif
    return fapi2::putScom(i_target, PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011809));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0,
           PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011809));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0,
           PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011809));
#endif
    return i_data.extractToRight<PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0,
           PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011809));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1,
           PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011809));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1,
           PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011809));
#endif
    return i_data.extractToRight<PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1,
           PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011809));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011809));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011809));
#endif
    return o_data.setBit<PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011809));
#endif
    return o_data.clearBit<PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011809));
#endif
    return i_data.extractToRight<PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011809));
#endif
    return i_data.getBit<PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x301180e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x301180e;
#endif
    return fapi2::getScom(i_target, PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x301180e));
#endif
    return fapi2::putScom(i_target, PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301180e));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2,
           PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301180e));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2,
           PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x301180e));
#endif
    return i_data.extractToRight<PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2,
           PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3011855;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x3011855;
#endif
    return fapi2::getScom(i_target, PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x3011855));
#endif
    return fapi2::putScom(i_target, PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG_PE_DFREEZE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011855));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG_PE_DFREEZE,
           PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG_PE_DFREEZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG_PE_DFREEZE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG_PE_DFREEZE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011855));
#endif
    return o_data.insertFromRight<PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG_PE_DFREEZE,
           PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG_PE_DFREEZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG_PE_DFREEZE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG_PE_DFREEZE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x3011855));
#endif
    return i_data.extractToRight<PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG_PE_DFREEZE,
           PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG_PE_DFREEZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_PE_DFREEZE_REG_PE_DFREEZE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
