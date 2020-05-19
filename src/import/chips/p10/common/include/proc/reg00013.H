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


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
