/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00067.H $         */
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

#ifndef __PROC_REG00067_H_
#define __PROC_REG00067_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_MEM_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_SRAM_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_5]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA1_7]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SRD1B(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SRD1B;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SRD1B(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SRD1B;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SRD1B, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1B]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SRD1B(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD1B));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SRD1B, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1B]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD1B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B,
           TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD1B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B,
           TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD1B));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B,
           TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD1B_OCB_OCI_O2SRD1B_O2S_RDATA_1B]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0_BASE]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS,
           TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS,
           TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS,
           TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG1_OCB_OCI_OCCFLG1_OCC_FLAGS]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C,
           TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C,
           TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR0C_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C,
           TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OIRR0C_OCB_OCI_OIRR0C_INTERRUPT_ROUTE_0_C]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPITASV2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITASV2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITASV2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITASV2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPITASV2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITASV2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_5]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITASV2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7,
           TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPITASV2_7]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OTR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OTR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OTR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OTR0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OTR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OTR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OTR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OTR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OTR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OTR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OTR0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMEOUT_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_CONTROL_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_AUTO_RELOAD_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_SPARE_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0,
           TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0,
           TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OTR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0,
           TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OTR0_TIMER_0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_P2S_100NS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_P2S_100NS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_100NS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_P2S_100NS]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_100NS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_P2S_100NS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_100NS;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_100NS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_100NS]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_P2S_100NS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_P2S_100NS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_100NS));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_100NS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_P2S_100NS]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_100NS));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS,
           TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_100NS));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS,
           TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_100NS));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS,
           TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_100NS_OCB_OCI_P2S_100NS]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_P2S_CMD(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_CMD;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_P2S_CMD(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_CMD;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_CMD, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_P2S_CMD(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CMD));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_CMD, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CMD));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CMD));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CMD));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CMD));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CMD));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CMD));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_CMD_OCB_OCI_P2S_CMD_START_COMMAND]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
