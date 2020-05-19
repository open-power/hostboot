/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00005.H $         */
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

#ifndef __PROC_REG00005_H_
#define __PROC_REG00005_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[MCD_MCC_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_MCC_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_MCC_FIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MCD_MCC_FIR_REG_RW]

//>> GET_[MCD_MCC_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_MCC_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_MCC_FIR_REG_RW;
#endif
    return fapi2::getScom(i_target, MCD_MCC_FIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_RW]

//>> PUT_[MCD_MCC_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_MCC_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MCD_MCC_FIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MCD_MCC_FIR_REG_RW]

//>> SET_[MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR]

//>> SET_[MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR]

//>> SET_[MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR]

//>> CLEAR_[MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR]

//>> GET_[MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR]
static inline fapi2::buffer<uint64_t>& GET_MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR]

//>> GET_[MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR]
static inline bool GET_MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_ARRAY_ECC_UE_ERR]

//>> SET_[MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR]

//>> SET_[MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR]

//>> SET_[MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR]

//>> CLEAR_[MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR]

//>> GET_[MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR]
static inline fapi2::buffer<uint64_t>& GET_MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR]

//>> GET_[MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR]
static inline bool GET_MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_ARRAY_ECC_CE_ERR]

//>> SET_[MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR]

//>> SET_[MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR]

//>> SET_[MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR]

//>> CLEAR_[MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR]

//>> GET_[MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR]

//>> GET_[MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR]
static inline bool GET_MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_PB_ADDR_PARITY_ERR]

//>> SET_[MCD_MCC_FIR_REG_SM_OR_CASE_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_SM_OR_CASE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_SM_OR_CASE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_MCC_FIR_REG_SM_OR_CASE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_SM_OR_CASE_ERR]

//>> SET_[MCD_MCC_FIR_REG_SM_OR_CASE_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_SM_OR_CASE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_SM_OR_CASE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_MCC_FIR_REG_SM_OR_CASE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_SM_OR_CASE_ERR]

//>> SET_[MCD_MCC_FIR_REG_SM_OR_CASE_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_SM_OR_CASE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MCD_MCC_FIR_REG_SM_OR_CASE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_MCC_FIR_REG_SM_OR_CASE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_SM_OR_CASE_ERR]

//>> CLEAR_[MCD_MCC_FIR_REG_SM_OR_CASE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_MCC_FIR_REG_SM_OR_CASE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_MCC_FIR_REG_SM_OR_CASE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_MCC_FIR_REG_SM_OR_CASE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_MCC_FIR_REG_SM_OR_CASE_ERR]

//>> GET_[MCD_MCC_FIR_REG_SM_OR_CASE_ERR]
static inline fapi2::buffer<uint64_t>& GET_MCD_MCC_FIR_REG_SM_OR_CASE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_MCC_FIR_REG_SM_OR_CASE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_MCC_FIR_REG_SM_OR_CASE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_SM_OR_CASE_ERR]

//>> GET_[MCD_MCC_FIR_REG_SM_OR_CASE_ERR]
static inline bool GET_MCD_MCC_FIR_REG_SM_OR_CASE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MCD_MCC_FIR_REG_SM_OR_CASE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_MCC_FIR_REG_SM_OR_CASE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_SM_OR_CASE_ERR]

//>> SET_[MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR]

//>> SET_[MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR]

//>> SET_[MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR]

//>> CLEAR_[MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR]

//>> GET_[MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR]
static inline fapi2::buffer<uint64_t>& GET_MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR]

//>> GET_[MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR]
static inline bool GET_MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_CL_PROBE_PB_HANG_ERR]

//>> SET_[MCD_MCC_FIR_REG_CRESP_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_CRESP_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_CRESP_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_MCC_FIR_REG_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_CRESP_ADDR_ERR]

//>> SET_[MCD_MCC_FIR_REG_CRESP_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_CRESP_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_CRESP_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_MCC_FIR_REG_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_CRESP_ADDR_ERR]

//>> SET_[MCD_MCC_FIR_REG_CRESP_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_CRESP_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MCD_MCC_FIR_REG_CRESP_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_MCC_FIR_REG_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_CRESP_ADDR_ERR]

//>> CLEAR_[MCD_MCC_FIR_REG_CRESP_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_MCC_FIR_REG_CRESP_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_MCC_FIR_REG_CRESP_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_MCC_FIR_REG_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_MCC_FIR_REG_CRESP_ADDR_ERR]

//>> GET_[MCD_MCC_FIR_REG_CRESP_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_MCD_MCC_FIR_REG_CRESP_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_MCC_FIR_REG_CRESP_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_MCC_FIR_REG_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_CRESP_ADDR_ERR]

//>> GET_[MCD_MCC_FIR_REG_CRESP_ADDR_ERR]
static inline bool GET_MCD_MCC_FIR_REG_CRESP_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MCD_MCC_FIR_REG_CRESP_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_MCC_FIR_REG_CRESP_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_CRESP_ADDR_ERR]

//>> SET_[MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR]

//>> SET_[MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR]

//>> SET_[MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR]

//>> CLEAR_[MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR]

//>> GET_[MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& GET_MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR]

//>> GET_[MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR]
static inline bool GET_MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_UNSOLICITED_CRESP_ERR]

//>> SET_[MCD_MCC_FIR_REG_TTAG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_TTAG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_TTAG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_MCC_FIR_REG_TTAG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_TTAG_PARITY_ERR]

//>> SET_[MCD_MCC_FIR_REG_TTAG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_TTAG_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_TTAG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_MCC_FIR_REG_TTAG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_TTAG_PARITY_ERR]

//>> SET_[MCD_MCC_FIR_REG_TTAG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_TTAG_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MCD_MCC_FIR_REG_TTAG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_MCC_FIR_REG_TTAG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_TTAG_PARITY_ERR]

//>> CLEAR_[MCD_MCC_FIR_REG_TTAG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_MCC_FIR_REG_TTAG_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_MCC_FIR_REG_TTAG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_MCC_FIR_REG_TTAG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_MCC_FIR_REG_TTAG_PARITY_ERR]

//>> GET_[MCD_MCC_FIR_REG_TTAG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_MCD_MCC_FIR_REG_TTAG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_MCC_FIR_REG_TTAG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_MCC_FIR_REG_TTAG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_TTAG_PARITY_ERR]

//>> GET_[MCD_MCC_FIR_REG_TTAG_PARITY_ERR]
static inline bool GET_MCD_MCC_FIR_REG_TTAG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MCD_MCC_FIR_REG_TTAG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_MCC_FIR_REG_TTAG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_TTAG_PARITY_ERR]

//>> SET_[MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR]

//>> SET_[MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR]

//>> SET_[MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR]

//>> CLEAR_[MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR]

//>> GET_[MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR]
static inline fapi2::buffer<uint64_t>& GET_MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR]

//>> GET_[MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR]
static inline bool GET_MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_FIR_REG_UPDATE_ERR]

//>> SET_[MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR]

//>> SET_[MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR]

//>> SET_[MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR]

//>> CLEAR_[MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR]

//>> GET_[MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& GET_MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR]

//>> GET_[MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR]
static inline bool GET_MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_ACK_DEAD_CRESP_ERR]

//>> SET_[MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR]

//>> SET_[MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR]

//>> SET_[MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR]

//>> CLEAR_[MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR]

//>> GET_[MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR]

//>> GET_[MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR]
static inline bool GET_MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_CFG_REG_PARITY_ERR]

//>> PREP_[NX_PBI_RNG_ST1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_RNG_ST1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_ST1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NX_PBI_RNG_ST1]

//>> GET_[NX_PBI_RNG_ST1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_RNG_ST1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_ST1;
#endif
    return fapi2::getScom(i_target, NX_PBI_RNG_ST1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NX_PBI_RNG_ST1]

//>> PUT_[NX_PBI_RNG_ST1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_RNG_ST1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST1));
#endif
    return fapi2::putScom(i_target, NX_PBI_RNG_ST1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NX_PBI_RNG_ST1]


//>> SET_[NX_PBI_RNG_ST1_SOFT_FAIL_TH]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST1_SOFT_FAIL_TH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST1));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST1_SOFT_FAIL_TH,
           NX_PBI_RNG_ST1_SOFT_FAIL_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST1_SOFT_FAIL_TH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST1_SOFT_FAIL_TH]

//>> SET_[NX_PBI_RNG_ST1_SOFT_FAIL_TH]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST1_SOFT_FAIL_TH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST1));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST1_SOFT_FAIL_TH,
           NX_PBI_RNG_ST1_SOFT_FAIL_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST1_SOFT_FAIL_TH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST1_SOFT_FAIL_TH]

//>> GET_[NX_PBI_RNG_ST1_SOFT_FAIL_TH]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST1_SOFT_FAIL_TH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST1));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST1_SOFT_FAIL_TH,
           NX_PBI_RNG_ST1_SOFT_FAIL_TH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST1_SOFT_FAIL_TH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST1_SOFT_FAIL_TH]

//>> SET_[NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST1));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN,
           NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN]

//>> SET_[NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST1));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN,
           NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN]

//>> GET_[NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST1));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN,
           NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN]

//>> SET_[NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST1));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX,
           NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX]

//>> SET_[NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST1));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX,
           NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX]

//>> GET_[NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST1));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX,
           NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX]

//>> PREP_[NX_PBI_SHIM_ERAT_STATUS_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_SHIM_ERAT_STATUS_CONTROL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_SHIM_ERAT_STATUS_CONTROL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NX_PBI_SHIM_ERAT_STATUS_CONTROL]

//>> GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_SHIM_ERAT_STATUS_CONTROL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_SHIM_ERAT_STATUS_CONTROL;
#endif
    return fapi2::getScom(i_target, NX_PBI_SHIM_ERAT_STATUS_CONTROL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL]

//>> PUT_[NX_PBI_SHIM_ERAT_STATUS_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_SHIM_ERAT_STATUS_CONTROL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return fapi2::putScom(i_target, NX_PBI_SHIM_ERAT_STATUS_CONTROL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NX_PBI_SHIM_ERAT_STATUS_CONTROL]


//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.setBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS]

//>> CLEAR_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.clearBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS]

//>> GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return i_data.extractToRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS]

//>> GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS]
static inline bool GET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return i_data.getBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_FORCE_ERAT_BYPASS]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.setBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE]

//>> CLEAR_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.clearBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE]

//>> GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return i_data.extractToRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE]

//>> GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE]
static inline bool GET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return i_data.getBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_IDLE]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.setBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY]

//>> CLEAR_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.clearBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY]

//>> GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return i_data.extractToRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY]

//>> GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY]
static inline bool GET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return i_data.getBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_ERAT_VALID_ENTRY]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.setBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER]

//>> CLEAR_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.clearBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER]

//>> GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return i_data.extractToRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER]

//>> GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER]
static inline bool GET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return i_data.getBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_ERAT_HIT_UNDER_BARRIER]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.setBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE]

//>> CLEAR_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.clearBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE]

//>> GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return i_data.extractToRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE]

//>> GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE]
static inline bool GET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return i_data.getBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_PROMOTE]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.setBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER]

//>> CLEAR_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.clearBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER]

//>> GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return i_data.extractToRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER]

//>> GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER]
static inline bool GET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return i_data.getBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKIN_HANG_TIMER]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.setBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER]

//>> CLEAR_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.clearBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER]

//>> GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return i_data.extractToRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER]

//>> GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER]
static inline bool GET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return i_data.getBit<NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_DISABLE_CHECKOUT_HANG_TIMER]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT,
           NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT]

//>> SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return o_data.insertFromRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT,
           NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT]

//>> GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_SHIM_ERAT_STATUS_CONTROL));
#endif
    return i_data.extractToRight<NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT,
           NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_SHIM_ERAT_STATUS_CONTROL_SPECULATIVE_CHECKIN_COUNT]

//>> PREP_[NX_PBI_UMAC_RNG_FAILED_INT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_UMAC_RNG_FAILED_INT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_UMAC_RNG_FAILED_INT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NX_PBI_UMAC_RNG_FAILED_INT]

//>> GET_[NX_PBI_UMAC_RNG_FAILED_INT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_UMAC_RNG_FAILED_INT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_UMAC_RNG_FAILED_INT;
#endif
    return fapi2::getScom(i_target, NX_PBI_UMAC_RNG_FAILED_INT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NX_PBI_UMAC_RNG_FAILED_INT]

//>> PUT_[NX_PBI_UMAC_RNG_FAILED_INT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_UMAC_RNG_FAILED_INT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_RNG_FAILED_INT));
#endif
    return fapi2::putScom(i_target, NX_PBI_UMAC_RNG_FAILED_INT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NX_PBI_UMAC_RNG_FAILED_INT]


//>> SET_[NX_PBI_UMAC_RNG_FAILED_INT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_RNG_FAILED_INT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_RNG_FAILED_INT));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_RNG_FAILED_INT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_UMAC_RNG_FAILED_INT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_RNG_FAILED_INT_ENABLE]

//>> SET_[NX_PBI_UMAC_RNG_FAILED_INT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_RNG_FAILED_INT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_RNG_FAILED_INT));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_RNG_FAILED_INT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_UMAC_RNG_FAILED_INT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_RNG_FAILED_INT_ENABLE]

//>> SET_[NX_PBI_UMAC_RNG_FAILED_INT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_RNG_FAILED_INT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_RNG_FAILED_INT));
#endif
    return o_data.setBit<NX_PBI_UMAC_RNG_FAILED_INT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_UMAC_RNG_FAILED_INT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_RNG_FAILED_INT_ENABLE]

//>> CLEAR_[NX_PBI_UMAC_RNG_FAILED_INT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_UMAC_RNG_FAILED_INT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_RNG_FAILED_INT));
#endif
    return o_data.clearBit<NX_PBI_UMAC_RNG_FAILED_INT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_UMAC_RNG_FAILED_INT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_UMAC_RNG_FAILED_INT_ENABLE]

//>> GET_[NX_PBI_UMAC_RNG_FAILED_INT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_RNG_FAILED_INT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_RNG_FAILED_INT));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_RNG_FAILED_INT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_UMAC_RNG_FAILED_INT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_RNG_FAILED_INT_ENABLE]

//>> GET_[NX_PBI_UMAC_RNG_FAILED_INT_ENABLE]
static inline bool GET_NX_PBI_UMAC_RNG_FAILED_INT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_RNG_FAILED_INT));
#endif
    return i_data.getBit<NX_PBI_UMAC_RNG_FAILED_INT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_UMAC_RNG_FAILED_INT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_RNG_FAILED_INT_ENABLE]

//>> SET_[NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_RNG_FAILED_INT));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS,
           NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS]

//>> SET_[NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_RNG_FAILED_INT));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS,
           NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS]

//>> GET_[NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_RNG_FAILED_INT));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS,
           NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS]

//>> PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT]

//>> PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT]


//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE,
           PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT_PB_CFG_SPARE]

//>> PREP_[MCD_MCC_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_MCC_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_MCC_FIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MCD_MCC_FIR_REG_WO_AND]

//>> GET_[MCD_MCC_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_MCC_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_MCC_FIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, MCD_MCC_FIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_WO_AND]

//>> PUT_[MCD_MCC_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_MCC_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MCD_MCC_FIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MCD_MCC_FIR_REG_WO_AND]

//>> PREP_[MCD_MCC_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_MCC_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_MCC_FIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MCD_MCC_FIR_REG_WO_OR]

//>> GET_[MCD_MCC_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_MCC_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_MCC_FIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, MCD_MCC_FIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MCD_MCC_FIR_REG_WO_OR]

//>> PUT_[MCD_MCC_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_MCC_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCD_MCC_FIR_REG_RW, MCD_MCC_FIR_REG_WO_AND, MCD_MCC_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MCD_MCC_FIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MCD_MCC_FIR_REG_WO_OR]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
