/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00013.H $         */
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

#ifndef __PROC_REG00013_H_
#define __PROC_REG00013_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_I_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1_B_ADDRESS]

//>> PREP_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR]

//>> GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR]

//>> PUT_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR]


//>> SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_TIMEOUT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW]

//>> SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW]

//>> SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW]

//>> GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW]

//>> GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW]
static inline bool GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_ICU_RNW]

//>> SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3,
           TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3]

//>> SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3,
           TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3]

//>> GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3,
           TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_2_3]

//>> SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_TIMEOUT_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW]

//>> SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW]

//>> SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW]

//>> GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW]

//>> GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW]
static inline bool GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_DCU_RNW]

//>> SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7,
           TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7]

//>> SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7,
           TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7]

//>> GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7,
           TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR_RESERVED_6_7]

//>> PREP_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1]

//>> PUT_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1]


//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1]

//>> SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1]

//>> GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1,
           TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRACT1_OCC_SCOM_OCCLFIRACT1_FIR_ACTION1]

//>> PREP_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO]

//>> PUT_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO]


//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HCP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RIP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SIP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_SIBRC]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRH]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_SMS]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_LP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_PTR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_ST]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR]

//>> PREP_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG]

//>> PUT_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG]


//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RECEIVE_DELAY]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_RESERVED]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_TRACE_SELECT]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_RESET_CONTROL]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_ECC_CONTROL]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_SPI_SLAVE_RESET]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]

//>> PREP_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW]

//>> PUT_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW]

//>> PREP_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR]

//>> PUT_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR]

//>> PREP_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR]

//>> PUT_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR]


//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_SPARE2]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_RW, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR,
                           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
