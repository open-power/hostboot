/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00001.H $         */
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

#ifndef __PERV_REG00001_H_
#define __PERV_REG00001_H_

namespace scomt
{
namespace perv
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA2_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA2_TR1_CONFIG_5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA2_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA2_TR1_CONFIG_5;
#endif
    return fapi2::getScom(i_target, TRA2_TR1_CONFIG_5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA2_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_5));
#endif
    return fapi2::putScom(i_target, TRA2_TR1_CONFIG_5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA2_TR1_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA2_TR1_CONFIG_5_C,
           TRA2_TR1_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR1_CONFIG_5_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA2_TR1_CONFIG_5_C,
           TRA2_TR1_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR1_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_5));
#endif
    return i_data.extractToRight<TRA2_TR1_CONFIG_5_C,
           TRA2_TR1_CONFIG_5_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR1_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA2_TR1_CONFIG_5_D,
           TRA2_TR1_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR1_CONFIG_5_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA2_TR1_CONFIG_5_D,
           TRA2_TR1_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR1_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_5));
#endif
    return i_data.extractToRight<TRA2_TR1_CONFIG_5_D,
           TRA2_TR1_CONFIG_5_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA3_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA3_TR0_CONFIG_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA3_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA3_TR0_CONFIG_3;
#endif
    return fapi2::getScom(i_target, TRA3_TR0_CONFIG_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA3_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA3_TR0_CONFIG_3));
#endif
    return fapi2::putScom(i_target, TRA3_TR0_CONFIG_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA3_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA3_TR0_CONFIG_3_C,
           TRA3_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA3_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA3_TR0_CONFIG_3_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA3_TR0_CONFIG_3_C,
           TRA3_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA3_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA3_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<TRA3_TR0_CONFIG_3_C,
           TRA3_TR0_CONFIG_3_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA3_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA3_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA3_TR0_CONFIG_3_D,
           TRA3_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA3_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA3_TR0_CONFIG_3_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA3_TR0_CONFIG_3_D,
           TRA3_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA3_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA3_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<TRA3_TR0_CONFIG_3_D,
           TRA3_TR0_CONFIG_3_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA3_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA4_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA4_TR0_CONFIG_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA4_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA4_TR0_CONFIG_2;
#endif
    return fapi2::getScom(i_target, TRA4_TR0_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA4_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA4_TR0_CONFIG_2));
#endif
    return fapi2::putScom(i_target, TRA4_TR0_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA4_TR0_CONFIG_2_A,
           TRA4_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA4_TR0_CONFIG_2_A,
           TRA4_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA4_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<TRA4_TR0_CONFIG_2_A,
           TRA4_TR0_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA4_TR0_CONFIG_2_B,
           TRA4_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA4_TR0_CONFIG_2_B,
           TRA4_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA4_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<TRA4_TR0_CONFIG_2_B,
           TRA4_TR0_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA5_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA5_TR1_CONFIG_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA5_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA5_TR1_CONFIG_4;
#endif
    return fapi2::getScom(i_target, TRA5_TR1_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA5_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_4));
#endif
    return fapi2::putScom(i_target, TRA5_TR1_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA5_TR1_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA5_TR1_CONFIG_4_A,
           TRA5_TR1_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA5_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA5_TR1_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA5_TR1_CONFIG_4_A,
           TRA5_TR1_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA5_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA5_TR1_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_4));
#endif
    return i_data.extractToRight<TRA5_TR1_CONFIG_4_A,
           TRA5_TR1_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA5_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA5_TR1_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA5_TR1_CONFIG_4_B,
           TRA5_TR1_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA5_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA5_TR1_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA5_TR1_CONFIG_4_B,
           TRA5_TR1_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA5_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA5_TR1_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_4));
#endif
    return i_data.extractToRight<TRA5_TR1_CONFIG_4_B,
           TRA5_TR1_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA5_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA6_TR1_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA6_TR1_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA6_TR1_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA6_TR1_CONFIG;
#endif
    return fapi2::getScom(i_target, TRA6_TR1_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA6_TR1_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return fapi2::putScom(i_target, TRA6_TR1_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_EXTEND_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_EXTEND_TRIG_MODE,
           TRA6_TR1_CONFIG_EXTEND_TRIG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_EXTEND_TRIG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_EXTEND_TRIG_MODE,
           TRA6_TR1_CONFIG_EXTEND_TRIG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_EXTEND_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_EXTEND_TRIG_MODE,
           TRA6_TR1_CONFIG_EXTEND_TRIG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_BANK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_BANK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_BANK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_BANK_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA6_TR1_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_ENH_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_ENH_TRACE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_ENH_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_ENH_TRACE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA6_TR1_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL,
           TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL,
           TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL,
           TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_TRACE_RUN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_TRACE_RUN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_TRACE_RUN_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA6_TR1_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_TRACE_RUN_STICKY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_STICKY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_TRACE_RUN_STICKY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_TRACE_RUN_STICKY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA6_TR1_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA6_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA6_TR1_CONFIG_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA6_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA6_TR1_CONFIG_3;
#endif
    return fapi2::getScom(i_target, TRA6_TR1_CONFIG_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA6_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG_3));
#endif
    return fapi2::putScom(i_target, TRA6_TR1_CONFIG_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_3_C,
           TRA6_TR1_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_3_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_3_C,
           TRA6_TR1_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG_3));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_3_C,
           TRA6_TR1_CONFIG_3_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_3_D,
           TRA6_TR1_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_3_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_3_D,
           TRA6_TR1_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG_3));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_3_D,
           TRA6_TR1_CONFIG_3_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA6_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA7_TR0_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA7_TR0_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA7_TR0_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA7_TR0_CONFIG;
#endif
    return fapi2::getScom(i_target, TRA7_TR0_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA7_TR0_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return fapi2::putScom(i_target, TRA7_TR0_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_EXTEND_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_EXTEND_TRIG_MODE,
           TRA7_TR0_CONFIG_EXTEND_TRIG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_EXTEND_TRIG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_EXTEND_TRIG_MODE,
           TRA7_TR0_CONFIG_EXTEND_TRIG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_EXTEND_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_EXTEND_TRIG_MODE,
           TRA7_TR0_CONFIG_EXTEND_TRIG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_BANK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_BANK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_BANK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_BANK_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA7_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_ENH_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_ENH_TRACE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_ENH_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_ENH_TRACE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA7_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL,
           TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL,
           TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL,
           TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_TRACE_RUN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_TRACE_RUN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_TRACE_RUN_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA7_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_TRACE_RUN_STICKY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_STICKY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_TRACE_RUN_STICKY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_TRACE_RUN_STICKY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA7_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA7_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA7_TR0_CONFIG_5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA7_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA7_TR0_CONFIG_5;
#endif
    return fapi2::getScom(i_target, TRA7_TR0_CONFIG_5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA7_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_5));
#endif
    return fapi2::putScom(i_target, TRA7_TR0_CONFIG_5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_5_C,
           TRA7_TR0_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_5_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_5_C,
           TRA7_TR0_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_5));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_5_C,
           TRA7_TR0_CONFIG_5_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_5_D,
           TRA7_TR0_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_5_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_5_D,
           TRA7_TR0_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_5));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_5_D,
           TRA7_TR0_CONFIG_5_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_RW;
#endif
    return fapi2::getScom(i_target, XSTOP_MASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, XSTOP_MASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, XSTOP_MASK_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, XSTOP_MASK_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_WO_OR;
#endif
    return fapi2::getScom(i_target, XSTOP_MASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, XSTOP_MASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSTOP_MASK_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
