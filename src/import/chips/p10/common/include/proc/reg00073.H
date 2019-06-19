/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00073.H $         */
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

#ifndef __PROC_REG00073_H_
#define __PROC_REG00073_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIIAR_OCB_OCI_GPEXIIAR_IAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISPRG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISPRG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISPRG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISPRG0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISPRG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISPRG0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISPRG0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISPRG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_STAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_STAT;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_STAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_STAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3,
           TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3,
           TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3,
           TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B__CLEAR_STICKY_BITS_1B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SWD1B(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SWD1B;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SWD1B(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SWD1B;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SWD1B, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SWD1B(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD1B));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SWD1B, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD1B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD1B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD1B));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1,
           TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1,
           TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1,
           TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OITR1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OITR1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR1_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OITR1_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR1_RW, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR1_RW, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR1_RW, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR1_RW, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1,
           TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR1_RW, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1,
           TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR1_RW, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1,
           TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT2Q4_OCB_OCI_OPIT2Q4RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT5Q2_OCB_OCI_OPIT5Q2RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6_OCB_OCI_OPIT6Q6RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6_OCB_OCI_OPIT6Q6RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6_OCB_OCI_OPIT6Q6RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6_OCB_OCI_OPIT6Q6RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6_OCB_OCI_OPIT6Q6RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6_OCB_OCI_OPIT6Q6RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6_OCB_OCI_OPIT6Q6RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6_OCB_OCI_OPIT6Q6RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6_OCB_OCI_OPIT6Q6RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6_OCB_OCI_OPIT6Q6RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6_OCB_OCI_OPIT6Q6RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT6Q6_OCB_OCI_OPIT6Q6RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C16RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C2_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C24RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C9RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C11RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C23RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C9RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9PRB_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITBSV0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITBSV0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITBSV0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITBSV0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITBSV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITBSV0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPITIR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITIR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPITIR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITIR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITIR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPITIR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITIR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITIR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITIR_CHIPLET_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITIR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITIR_CHIPLET_ID,
           TP_TPCHIP_OCC_OCI_OCB_OPITIR_CHIPLET_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITIR_CHIPLET_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITIR_CHIPLET_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITIR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITIR_CHIPLET_ID,
           TP_TPCHIP_OCC_OCI_OCB_OPITIR_CHIPLET_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITIR_CHIPLET_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITIR_CHIPLET_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITIR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITIR_CHIPLET_ID,
           TP_TPCHIP_OCC_OCI_OCB_OPITIR_CHIPLET_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITIR_CHIPLET_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITIR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITIR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITIR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPITIR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITIR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITIR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITIR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITIR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPITIR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITIR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITIR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITIR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITIR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPITIR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITIR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA,
           TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA,
           TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA,
           TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA,
           TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA,
           TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA,
           TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_FSM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_RUN_TCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_TCK_WIDTH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_TCK_WIDTH,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_TCK_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_TCK_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_TCK_WIDTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_TCK_WIDTH,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_TCK_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_TCK_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_TCK_WIDTH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_TCK_WIDTH,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_TCK_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_TCK_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_CFG_DBG_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_JTAG_INPROG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_SRC_SEL_EQ1_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_RUN_TCK_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_TRST_B_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_IR_DR_EQ0_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_INPROG_WR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_STAT_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_IR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_DO_TAP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_WR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_JTAG_INSTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_JTAG_INSTR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_JTAG_INSTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_JTAG_INSTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_JTAG_INSTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_JTAG_INSTR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_JTAG_INSTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_JTAG_INSTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_JTAG_INSTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_JTAG_INSTR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_JTAG_INSTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_IC_JTAG_INSTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_SRAM_CTL_SRBV3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_SRAM_CTL_SRBV3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_SRAM_CTL_SRBV3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_SRAM_CTL_SRBV3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_SRAM_CTL_SRBV3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_SRAM_CTL_SRBV3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_SRAM_CTL_SRBV3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3,
           TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3,
           TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3,
           TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1_REGISTER1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1_REGISTER1,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1_REGISTER1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1_REGISTER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1_REGISTER1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1_REGISTER1,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1_REGISTER1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1_REGISTER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1_REGISTER1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1_REGISTER1,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1_REGISTER1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG1_REGISTER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115_REGISTER115(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115_REGISTER115,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115_REGISTER115_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115_REGISTER115 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115_REGISTER115(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115_REGISTER115,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115_REGISTER115_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115_REGISTER115 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115_REGISTER115(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115_REGISTER115,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115_REGISTER115_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG115_REGISTER115 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122_REGISTER122(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122_REGISTER122,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122_REGISTER122_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122_REGISTER122 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122_REGISTER122(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122_REGISTER122,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122_REGISTER122_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122_REGISTER122 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122_REGISTER122(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122_REGISTER122,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122_REGISTER122_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG122_REGISTER122 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15_REGISTER15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15_REGISTER15,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15_REGISTER15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15_REGISTER15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15_REGISTER15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15_REGISTER15,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15_REGISTER15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15_REGISTER15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15_REGISTER15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15_REGISTER15,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15_REGISTER15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG15_REGISTER15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22_REGISTER22(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22_REGISTER22,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22_REGISTER22_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22_REGISTER22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22_REGISTER22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22_REGISTER22,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22_REGISTER22_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22_REGISTER22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22_REGISTER22(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22_REGISTER22,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22_REGISTER22_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG22_REGISTER22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43_REGISTER43(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43_REGISTER43,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43_REGISTER43_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43_REGISTER43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43_REGISTER43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43_REGISTER43,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43_REGISTER43_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43_REGISTER43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43_REGISTER43(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43_REGISTER43,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43_REGISTER43_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG43_REGISTER43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74_REGISTER74(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74_REGISTER74,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74_REGISTER74_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74_REGISTER74 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74_REGISTER74(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74_REGISTER74,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74_REGISTER74_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74_REGISTER74 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74_REGISTER74(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74_REGISTER74,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74_REGISTER74_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG74_REGISTER74 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81_REGISTER81(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81_REGISTER81,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81_REGISTER81_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81_REGISTER81 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81_REGISTER81(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81_REGISTER81,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81_REGISTER81_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81_REGISTER81 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81_REGISTER81(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81_REGISTER81,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81_REGISTER81_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG81_REGISTER81 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_CPLT_CTRL4_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL4_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_CPLT_CTRL4_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL4_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL4_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_CPLT_CTRL4_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL4_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL4_RW, TP_TPCHIP_TPC_CPLT_CTRL4_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_EPS_DBG_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_DBG_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_DBG_MODE_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_EPS_DBG_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_EPS_DBG_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_EPS_DBG_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_GLB_BRCST_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_GLB_BRCST_MODE,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_GLB_BRCST_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_GLB_BRCST_MODE,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_GLB_BRCST_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_GLB_BRCST_MODE,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_SEL_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_SEL_MODE,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_SEL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_SEL_MODE,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_SEL_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_SEL_MODE,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRIG_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRIG_SEL_MODE,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRIG_SEL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRIG_SEL_MODE,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRIG_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRIG_SEL_MODE,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_RUN_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_RUN_STATUS,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_RUN_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_RUN_STATUS,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_RUN_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_RUN_STATUS,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS,
           TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_RW, TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT,
           TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT,
           TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT,
           TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT,
           TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT,
           TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT,
           TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_CNTR_REF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_CNTR_REF,
           TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_CNTR_REF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_CNTR_REF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_CNTR_REF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_CNTR_REF,
           TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_CNTR_REF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_CNTR_REF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_CNTR_REF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_CNTR_REF,
           TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_CNTR_REF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_ITR_FMU_PULSE_GEN_REG_CNTR_REF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_ITR_FMU_KVREF_AND_VMEAS_MODE_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_SCAN_LONG_ROTATE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_SCAN_LONG_ROTATE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_SCAN_LONG_ROTATE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_SCAN_LONG_ROTATE;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_SCAN_LONG_ROTATE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_SCAN_LONG_ROTATE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_SCAN_LONG_ROTATE));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_SCAN_LONG_ROTATE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}



}
}

#endif
