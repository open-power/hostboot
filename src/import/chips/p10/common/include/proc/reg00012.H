/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00012.H $         */
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

#ifndef __PROC_REG00012_H_
#define __PROC_REG00012_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_EG_SCF_PGMIG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_PGMIG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_EG_SCF_PGMIG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_PGMIG1;
#endif
    return fapi2::getScom(i_target, VAS_VA_EG_SCF_PGMIG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_EG_SCF_PGMIG1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PGMIG1));
#endif
    return fapi2::putScom(i_target, VAS_VA_EG_SCF_PGMIG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_RGERRRPT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_RGERRRPT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_RGERRRPT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_RGERRRPT;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_RGERRRPT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_RGERRRPT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_RGERRRPT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_RMABAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_RMABAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_RMABAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_RMABAR;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_RMABAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_RMABAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RMABAR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_RMABAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RMABAR_RMA_BAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RMABAR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RMABAR_RMA_BAR,
           VAS_VA_RG_SCF_RMABAR_RMA_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RMABAR_RMA_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RMABAR_RMA_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RMABAR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RMABAR_RMA_BAR,
           VAS_VA_RG_SCF_RMABAR_RMA_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RMABAR_RMA_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RMABAR_RMA_BAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RMABAR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RMABAR_RMA_BAR,
           VAS_VA_RG_SCF_RMABAR_RMA_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RMABAR_RMA_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON2BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON2BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON2BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON2BAR;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON2BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON2BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON2BAR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON2BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON6CMP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON6CMP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON6CMP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON6CMP;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON6CMP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON6CMP(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON6CMP));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON6CMP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON7WID(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON7WID;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON7WID(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON7WID;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON7WID, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON7WID(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON7WID));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON7WID, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}



}
}

#endif
