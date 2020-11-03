/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00052.H $         */
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

#ifndef __PROC_REG00052_H_
#define __PROC_REG00052_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR]


//>> SET_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR,
           TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR]

//>> SET_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR,
           TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR]

//>> GET_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR,
           TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SIB]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_SMS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR_MCS]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSES1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSES1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSES1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSES1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSES1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSES1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B,
           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B,
           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B,
           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OISR1_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OISR1_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OISR1_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OISR1_RO]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OISR1_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_RO]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OISR1_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OISR1_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OISR1_RO]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_P2S_CR2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_CR2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_CR2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_CR2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR2]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_P2S_CR2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_CR2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR2]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
