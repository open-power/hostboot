/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00012.H $         */
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

#ifndef __PROC_REG00012_H_
#define __PROC_REG00012_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_CR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_CR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_CR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_CR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_G0ISR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G0ISR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_G0ISR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G0ISR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G0ISR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_G0ISR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G0ISR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G0ISR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G0ISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G0ISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G0ISR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_G1ISR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G1ISR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_G1ISR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G1ISR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G1ISR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_G1ISR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G1ISR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G1ISR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G1ISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G1ISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G1ISR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_G2ISR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G2ISR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_G2ISR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G2ISR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G2ISR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_G2ISR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G2ISR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G2ISR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G2ISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G2ISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G2ISR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_G3ISR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G3ISR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_G3ISR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G3ISR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G3ISR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_G3ISR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G3ISR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G3ISR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G3ISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G3ISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G3ISR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SST1A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SST1A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SST1A;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SST1A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SST1A(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SST1A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4,
           TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4,
           TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4,
           TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
