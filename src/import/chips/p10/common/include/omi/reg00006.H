/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00006.H $          */
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

#ifndef __OMI_REG00006_H_
#define __OMI_REG00006_H_

namespace scomt
{
namespace omi
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_MCWATDATA0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9a;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_MCWATDATA0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9a));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_MCWATDATA1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9b;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_MCWATDATA1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f9b));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9b));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9b));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9b));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA1_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9b));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9b));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9b));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA1_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_MCWATDATA2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9c;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_MCWATDATA2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f9c));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9c));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9c));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9c));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA2_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9c));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9c));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9c));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA2_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_MCWATDATA3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9d;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_MCWATDATA3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f9d));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9d));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9d));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9d));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA3_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9d));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9d));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9d));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA3_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_MCWATDATA4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9e;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_MCWATDATA4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f9e));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9e));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9e));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9e));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA4_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9e));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9e));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9e));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA4_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_MCWATDATA5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f9f;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_MCWATDATA5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f9f));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9f));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9f));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9f));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA5_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9f));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9f));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f9f));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA5_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_MCWATDATA6(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA6(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa0;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA6, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_MCWATDATA6(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fa0));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA6, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa0));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa0));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa0));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA6_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa0));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa0));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa0));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA6_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_MCWATDATA7(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA7(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa1;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA7, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_MCWATDATA7(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fa1));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA7, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa1));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa1));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa1));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA7_PATTERN_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa1));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa1));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa1));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA7_MASK_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_MCWATDATA8(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA8(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa2;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA8, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_MCWATDATA8(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fa2));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA8, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa2));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa2));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa2));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA8_PATTERN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa2));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa2));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa2));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA8_MASK_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_MCWATDATA9(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010fa3;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA9, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_MCWATDATA9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010fa3));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_MCWATDATA9, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa3));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa3));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa3));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA9_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa3));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa3));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010fa3));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL,
           MC1_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_MCWATDATA9_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_SPARE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f0f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_SPARE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f0f;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_SPARE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_SPARE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f0f));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_SPARE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_SPARE_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f0f));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_SPARE_SPARE,
           MC1_MISC_MBA_SCOMFIR_SPARE_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_SPARE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_SPARE_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f0f));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_SPARE_SPARE,
           MC1_MISC_MBA_SCOMFIR_SPARE_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_SPARE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_SPARE_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f0f));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_SPARE_SPARE,
           MC1_MISC_MBA_SCOMFIR_SPARE_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_SPARE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_WATCFG0AQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f80;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_WATCFG0AQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f80;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG0AQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_WATCFG0AQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f80));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG0AQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f80));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL,
           MC1_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f80));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL,
           MC1_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f80));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL,
           MC1_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_WATCFG0BQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f81;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_WATCFG0BQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f81;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG0BQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_WATCFG0BQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f81));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG0BQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f81));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA,
           MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f81));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA,
           MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f81));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA,
           MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_MSKA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f81));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL,
           MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f81));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL,
           MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f81));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL,
           MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0BQ_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_WATCFG0CQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f82;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_WATCFG0CQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f82;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG0CQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_WATCFG0CQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f82));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG0CQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f82));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB,
           MC1_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f82));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB,
           MC1_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f82));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB,
           MC1_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_WATCFG0DQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f83;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_WATCFG0DQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f83;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG0DQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_WATCFG0DQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f83));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG0DQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f83));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA,
           MC1_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f83));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA,
           MC1_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f83));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA,
           MC1_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_WATCFG0EQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f84;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_WATCFG0EQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f84;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG0EQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_WATCFG0EQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f84));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG0EQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f84));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB,
           MC1_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f84));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB,
           MC1_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f84));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB,
           MC1_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG0EQ_WATCFG0EQ_CFG_WAT_PATB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_WATCFG1AQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f85;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_WATCFG1AQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f85;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG1AQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_WATCFG1AQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f85));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG1AQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f85));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL,
           MC1_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f85));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL,
           MC1_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f85));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL,
           MC1_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_WATCFG1BQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f86;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_WATCFG1BQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f86;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG1BQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_WATCFG1BQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f86));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG1BQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f86));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA,
           MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f86));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA,
           MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f86));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA,
           MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_MSKA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f86));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL,
           MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f86));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL,
           MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f86));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL,
           MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1BQ_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_WATCFG1CQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f87;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_WATCFG1CQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f87;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG1CQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_WATCFG1CQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f87));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG1CQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f87));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB,
           MC1_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f87));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB,
           MC1_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f87));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB,
           MC1_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_WATCFG1DQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f88;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_WATCFG1DQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f88;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG1DQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_WATCFG1DQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f88));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG1DQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f88));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA,
           MC1_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f88));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA,
           MC1_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f88));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA,
           MC1_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_MISC_MBA_SCOMFIR_WATCFG1EQ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f89;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_MISC_MBA_SCOMFIR_WATCFG1EQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010f89;
#endif
    return fapi2::getScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG1EQ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_MISC_MBA_SCOMFIR_WATCFG1EQ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010f89));
#endif
    return fapi2::putScom(i_target, MC1_MISC_MBA_SCOMFIR_WATCFG1EQ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f89));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB,
           MC1_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f89));
#endif
    return o_data.insertFromRight<MC1_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB,
           MC1_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010f89));
#endif
    return i_data.extractToRight<MC1_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB,
           MC1_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_MISC_MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_AACR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c2c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_AACR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c2c;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_AACR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_AACR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c2c));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_AACR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_AACR_BUFFER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_AACR_BUFFER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AACR_BUFFER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_AACR_BUFFER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_AACR_BUFFER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AACR_BUFFER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_AACR_BUFFER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2c));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_AACR_BUFFER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AACR_BUFFER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_AACR_BUFFER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2c));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_AACR_BUFFER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AACR_BUFFER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_AACR_BUFFER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2c));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_AACR_BUFFER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AACR_BUFFER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_AACR_BUFFER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2c));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_AACR_BUFFER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AACR_BUFFER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_AACR_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_AACR_ADDRESS,
           MC1_PBI01_SCOMFIR_AACR_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AACR_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_AACR_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_AACR_ADDRESS,
           MC1_PBI01_SCOMFIR_AACR_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AACR_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_AACR_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2c));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_AACR_ADDRESS,
           MC1_PBI01_SCOMFIR_AACR_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AACR_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_AACR_AUTOINC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_AACR_AUTOINC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AACR_AUTOINC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_AACR_AUTOINC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_AACR_AUTOINC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AACR_AUTOINC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_AACR_AUTOINC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2c));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_AACR_AUTOINC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AACR_AUTOINC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_AACR_AUTOINC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2c));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_AACR_AUTOINC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AACR_AUTOINC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_AACR_AUTOINC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2c));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_AACR_AUTOINC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AACR_AUTOINC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_AACR_AUTOINC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2c));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_AACR_AUTOINC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AACR_AUTOINC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_AADR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c2d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_AADR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c2d;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_AADR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_AADR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c2d));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_AADR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_AADR_AADR_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_AADR_AADR_DATA,
           MC1_PBI01_SCOMFIR_AADR_AADR_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AADR_AADR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_AADR_AADR_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_AADR_AADR_DATA,
           MC1_PBI01_SCOMFIR_AADR_AADR_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AADR_AADR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_AADR_AADR_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2d));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_AADR_AADR_DATA,
           MC1_PBI01_SCOMFIR_AADR_AADR_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AADR_AADR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_AAER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c2e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_AAER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c2e;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_AAER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_AAER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c2e));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_AAER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_AAER_AAER_TAG_ECC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_AAER_AAER_TAG_ECC,
           MC1_PBI01_SCOMFIR_AAER_AAER_TAG_ECC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AAER_AAER_TAG_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_AAER_AAER_TAG_ECC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_AAER_AAER_TAG_ECC,
           MC1_PBI01_SCOMFIR_AAER_AAER_TAG_ECC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AAER_AAER_TAG_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_AAER_AAER_TAG_ECC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_AAER_AAER_TAG_ECC,
           MC1_PBI01_SCOMFIR_AAER_AAER_TAG_ECC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_AAER_AAER_TAG_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCERPT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c1e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCERPT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c1e;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCERPT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCERPT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCERPT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_AACR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCTO_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCERPT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c1f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCERPT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c1f;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCERPT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCERPT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCERPT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN0_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN1_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q,
           MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q,
           MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q,
           MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF0_OVERRUN_TAG_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q,
           MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q,
           MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q,
           MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_WDF1_OVERRUN_TAG_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1f));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT1_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCERPT2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c1a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCERPT2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c1a;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCERPT2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCERPT2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCERPT2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CAR3_SMF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_COLL_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_COLL_1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_OP_HIT_1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH0_TIMEOUT_MEM_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_CH1_TIMEOUT_MEM_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD0_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD1_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD2_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCERPT2_POP_RCMD3_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFGP0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c0a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFGP0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c0a;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFGP0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFGP0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFGP0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0_0_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0_0_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0_0_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0_0_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0_0_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGP0_0_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGP0_0_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGP0_0_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0_0_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0_0_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGP0_0_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGP0_0_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP,
           MC1_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP,
           MC1_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP,
           MC1_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION,
           MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION,
           MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION,
           MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0a));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFGP0A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c0e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFGP0A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c0e;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFGP0A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFGP0A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFGP0A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21,
           MC1_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21,
           MC1_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21,
           MC1_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_RESERVED_16_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0e));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFGP0E(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c16;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFGP0E(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c16;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFGP0E, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFGP0E(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFGP0E, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0E_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0E_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0E_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0E_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0E_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGP0E_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGP0E_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGP0E_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0E_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0E_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGP0E_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGP0E_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c16));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP0E_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFGP1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c0b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFGP1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c0b;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFGP1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFGP1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFGP1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1_1_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1_1_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1_1_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1_1_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1_1_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGP1_1_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGP1_1_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGP1_1_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1_1_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1_1_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGP1_1_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGP1_1_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP,
           MC1_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP,
           MC1_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP,
           MC1_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION,
           MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION,
           MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION,
           MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0b));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFGP1A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c0f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFGP1A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c0f;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFGP1A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFGP1A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFGP1A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_HOLE_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21,
           MC1_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21,
           MC1_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21,
           MC1_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_RESERVED_16_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1A_SMF_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFGP1E(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c17;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFGP1E(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c17;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFGP1E, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFGP1E(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFGP1E, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1E_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1E_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1E_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1E_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1E_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGP1E_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGP1E_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGP1E_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1E_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1E_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGP1E_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGP1E_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c17));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGP1E_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFGPM0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c20;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFGPM0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c20;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFGPM0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFGPM0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c20));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFGPM0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c20));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c20));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c20));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGPM0_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGPM0_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c20));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGPM0_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM0_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c20));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM0_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGPM0_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c20));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGPM0_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c20));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c20));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c20));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c20));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c20));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c20));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFGPM0A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c21;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFGPM0A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c21;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFGPM0A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFGPM0A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFGPM0A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21,
           MC1_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21,
           MC1_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21,
           MC1_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_RESERVED_16_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c21));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFGPM0E(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c1c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFGPM0E(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c1c;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFGPM0E, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFGPM0E(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFGPM0E, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0E_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0E_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0E_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0E_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0E_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGPM0E_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGPM0E_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGPM0E_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM0E_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM0E_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGPM0E_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGPM0E_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1c));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM0E_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFGPM1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c30;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFGPM1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c30;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFGPM1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFGPM1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c30));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFGPM1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c30));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c30));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c30));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGPM1_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGPM1_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c30));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGPM1_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM1_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c30));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM1_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGPM1_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c30));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGPM1_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c30));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c30));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c30));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c30));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c30));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c30));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE,
           MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFGPM1A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c31;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFGPM1A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c31;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFGPM1A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFGPM1A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFGPM1A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21,
           MC1_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21,
           MC1_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21,
           MC1_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_RESERVED_16_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c31));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFGPM1E(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c1d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFGPM1E(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c1d;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFGPM1E, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFGPM1E(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFGPM1E, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1E_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1E_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1E_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1E_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1E_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGPM1E_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGPM1E_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGPM1E_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM1E_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM1E_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGPM1E_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGPM1E_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_LOWER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c1d));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPM1E_UPPER_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFGPR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c0c;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFGPR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c0c;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFGPR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFGPR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFGPR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0c));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR0_MMIO_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFGPR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c0d;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFGPR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c0d;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFGPR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFGPR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFGPR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c0d));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS,
           MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFIR_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c00;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFIR_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c00;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFIR_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFIR_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFIR_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFIR_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c01;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFIR_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c01;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFIR_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFIR_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFIR_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFIR_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c02;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFIR_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c02;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFIR_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFIR_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFIR_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c02, 0xc010c01, 0xc010c00));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIR_RESERVED_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFIRACT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c06;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFIRACT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c06;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFIRACT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFIRACT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c06));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFIRACT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c06));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0,
           MC1_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c06));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0,
           MC1_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c06));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0,
           MC1_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFIRMASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c03;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c03;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFIRMASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c05, 0xc010c04, 0xc010c03));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFIRMASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c04;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c04;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFIRMASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c05, 0xc010c04, 0xc010c03));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFIRMASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c05;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c05;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFIRMASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c05, 0xc010c04, 0xc010c03));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFIRMASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c05, 0xc010c04, 0xc010c03));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK,
           MC1_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c05, 0xc010c04, 0xc010c03));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK,
           MC1_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c05, 0xc010c04, 0xc010c03));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK,
           MC1_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCFIRWOF(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c08;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCFIRWOF(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c08;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCFIRWOF, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCFIRWOF(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c08));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCFIRWOF, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c08));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF,
           MC1_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c08));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF,
           MC1_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c08));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF,
           MC1_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCFIRWOF_MCFIRWOF_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCLFSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c14;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCLFSR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c14;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCLFSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCLFSR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c14));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCLFSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c14));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT,
           MC1_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c14));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT,
           MC1_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c14));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT,
           MC1_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCLFSR_SERVED_2_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c14));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCLFSR_SERVED_2_4,
           MC1_PBI01_SCOMFIR_MCLFSR_SERVED_2_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCLFSR_SERVED_2_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCLFSR_SERVED_2_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c14));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCLFSR_SERVED_2_4,
           MC1_PBI01_SCOMFIR_MCLFSR_SERVED_2_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCLFSR_SERVED_2_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCLFSR_SERVED_2_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c14));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCLFSR_SERVED_2_4,
           MC1_PBI01_SCOMFIR_MCLFSR_SERVED_2_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCLFSR_SERVED_2_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCMODE0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c11;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCMODE0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c11;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCMODE0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCMODE0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCMODE0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_MCS_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE,
           MC1_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE,
           MC1_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE,
           MC1_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE,
           MC1_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE,
           MC1_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE,
           MC1_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_CL_FINE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY,
           MC1_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY,
           MC1_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY,
           MC1_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS,
           MC1_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS,
           MC1_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS,
           MC1_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ADD_HASH_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63,
           MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63,
           MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c11));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63,
           MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE0_RESERVED_41_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCMODE1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c12;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCMODE1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c12;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCMODE1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCMODE1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCMODE1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_M_BIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_SPEC_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CI,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CI,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CI,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_CI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS,
           MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c12));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCMODE2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c13;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCMODE2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c13;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCMODE2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCMODE2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCMODE2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_FORCE_SFSTAT_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0,
           MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0,
           MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0,
           MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_MDI0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15,
           MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15,
           MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15,
           MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_14_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_SHARED_PRESP_ABORT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_DISABLE_RETRY_LOST_CLAIM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22,
           MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22,
           MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22,
           MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_18_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_OP_HIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES,
           MC1_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES,
           MC1_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES,
           MC1_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_COLLISION_MODES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH,
           MC1_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH,
           MC1_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH,
           MC1_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_EPSILON_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_SPEC_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_ENABLE_FIR_HOST_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52,
           MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52,
           MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52,
           MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_46_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.setBit<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.clearBit<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.getBit<MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63,
           MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63,
           MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c13));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63,
           MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE2_RESERVED_57_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC1_PBI01_SCOMFIR_MCMODE3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c2f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC1_PBI01_SCOMFIR_MCMODE3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0xc010c2f;
#endif
    return fapi2::getScom(i_target, MC1_PBI01_SCOMFIR_MCMODE3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC1_PBI01_SCOMFIR_MCMODE3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0xc010c2f));
#endif
    return fapi2::putScom(i_target, MC1_PBI01_SCOMFIR_MCMODE3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10,
           MC1_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC1_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2f));
#endif
    return o_data.insertFromRight<MC1_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10,
           MC1_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC1_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0xc010c2f));
#endif
    return i_data.extractToRight<MC1_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10,
           MC1_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC1_PBI01_SCOMFIR_MCMODE3_MCMODE3_RESERVED_0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


}
}

#endif
