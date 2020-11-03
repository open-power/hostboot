/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00023.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __PROC_REG00023_H_
#define __PROC_REG00023_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_WATCHDOG_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPETSEL_FIT_SEL]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_CR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_CR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_CR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_CR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_FSM_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_DEVICE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPOL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CPHA]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_CLOCK_DIVIDER]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_NR_OF_FRAMES]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_SCRESP_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR1_BUSY_RESPONSE_CODE]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA5_3]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_RESET]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_ADC_RESET(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_RESET;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RESET]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RESET(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_RESET;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_RESET, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RESET]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_RESET]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_ADC_RESET(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RESET));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_RESET, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_RESET]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RESET));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RESET));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RESET));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL,
           TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL,
           TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL,
           TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA_OCB_OCI_ADC_WDATA_HWCTRL]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_G0ISR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_G0ISR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G0ISR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_G0ISR0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_G0ISR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G0ISR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G0ISR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_G0ISR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_G0ISR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G0ISR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G0ISR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_G0ISR0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G0ISR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0,
           TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G0ISR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0,
           TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G0ISR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0,
           TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR0_INTERRUPT_GPE0_STATUS_0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_G1ISR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_G1ISR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G1ISR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_G1ISR0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_G1ISR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G1ISR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G1ISR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_G1ISR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_G1ISR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G1ISR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G1ISR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_G1ISR0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G1ISR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0,
           TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G1ISR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0,
           TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G1ISR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0,
           TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR0_INTERRUPT_GPE1_STATUS_0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_G2ISR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_G2ISR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G2ISR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_G2ISR0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_G2ISR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G2ISR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G2ISR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_G2ISR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_G2ISR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G2ISR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G2ISR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_G2ISR0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G2ISR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0,
           TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G2ISR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0,
           TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G2ISR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0,
           TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR0_INTERRUPT_GPE2_STATUS_0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_G3ISR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_G3ISR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G3ISR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_G3ISR0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_G3ISR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G3ISR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G3ISR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_G3ISR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_G3ISR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G3ISR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G3ISR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_G3ISR0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G3ISR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0,
           TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G3ISR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0,
           TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G3ISR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0,
           TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR0_INTERRUPT_GPE3_STATUS_0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CMD0A_RESERVED_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0A_CLEAR_STICKY_BITS_0A]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL20_OCB_OCI_O2SCTRL20_O2S_INTER_FRAME_DELAY_0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_OUT_COUNT2_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_DELAY2_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS1_IN_COUNT2_1]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SRD2A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SRD2A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SRD2A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SRD2A;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SRD2A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2A]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SRD2A(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD2A));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SRD2A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2A]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD2A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A,
           TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD2A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A,
           TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD2A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A,
           TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2A_OCB_OCI_O2SRD2A_O2S_RDATA_2A]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SWD0A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SWD0A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SWD0A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SWD0A;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SWD0A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0A]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SWD0A(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD0A));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SWD0A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0A]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD0A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0A_OCB_OCI_O2SWD0A_O2S_WDATA_0A]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_OCI_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2_START]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_INTR_ACTION_0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_LENGTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_WRITE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_READ_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3_PUSH_ENABLE]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_I_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0_B_ADDRESS]

//>> PREP_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0]

//>> PUT_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0]


//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT0_OCC_SCOM_OCCLFIRACT0_FIR_ACTION0]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
